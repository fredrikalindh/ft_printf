/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:37:08 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/03 09:25:16 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	skip_atoi(const char **s)
{
	int		nb;

	nb = 0;
	while (**s >= '0' && **s <= '9')
		nb = nb * 10 + *((*s)++) - '0';
	(*s)--;
	return (nb);
}

static int	ft_iscspec(const char c)
{
	int		i;

	i = -1;
	while (C_SPEC[++i])
		if (C_SPEC[i] == c)
			return (i);
	return (-1);
}

int			ft_strnlen(char *str, int n)
{
	int		i;

	i = 0;
	if (n != -1)
		while (str[i] && i < n)
			i++;
	else
		while (str[i])
			i++;
	return (i);
}

void	ft_specifier(int *dir, const char **format)
{
	while (**format == 'h' || **format == 'l')
	{
		if (**format == 'h')
			SIGNED++;
		if (**format == 'l')
			LONG++;
		(*format)++;
	}
	(SPECIFIER = ft_iscspec(**format)) >= 0 ? (*format)++ : 0;
}

void	ft_initdir(int *dir, const char **format, va_list ap)
{
	while (ALLOWED)
	{
		if (**format == '.' && (*format)++ != NULL)
		{
			if (**format >= '0' && **format <= '9')
				PRECISION = skip_atoi(format);
			else if (**format == '*')
				PRECISION = va_arg(ap, int);
			PRECISION = (PRECISION < 0) ? 0 : PRECISION;
		}
		ZERO = (**format == '0') ? 1 : ZERO;
		LEFT = (**format == '-') ? 1 : LEFT;
		PLUS = (**format == '+') ? 1 : PLUS;
		SPACE = (**format == ' ') ? 1 : SPACE;
		SPECIAL = (**format == '#') ? 1 : SPECIAL;
		if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		else if (**format == '*')
		{
			WIDTH = va_arg(ap, int);
			if (WIDTH < 0 && (LEFT = 1) == 1)
				WIDTH = -WIDTH;
		}
		(*format)++;
	}
}
// void	ft_initdir(int *dir, const char **format, va_list ap)
// {
// 	while ((*format)++ && ALLOWED)
// 	{
// 		if (**format == '.' && (*format)++ != NULL)
// 		{
// 			if (**format >= '0' && **format <= '9')
// 				PRECISION = skip_atoi(format);
// 			else if (**format == '*')
// 				PRECISION = va_arg(ap, int);
// 			PRECISION = (PRECISION < 0) ? 0 : PRECISION;
// 		}
// 		ZERO = (**format == '0') ? 1 : ZERO;
// 		LEFT = (**format == '-') ? 1 : LEFT;
// 		PLUS = (**format == '+') ? 1 : PLUS;
// 		SPACE = (**format == ' ') ? 1 : SPACE;
// 		SPECIAL = (**format == '#') ? 1 : SPECIAL;
// 		if (**format >= '1' && **format <= '9')
// 			WIDTH = skip_atoi(format);
// 		else if (**format == '*')
// 		{
// 			WIDTH = va_arg(ap, int);
// 			if (WIDTH < 0 && (LEFT = 1) == 1)
// 				WIDTH = WIDTH * -1;
// 		}
// 	}
// 	(SPECIFIER = ft_iscspec(**format)) >= 0 ? (*format)++ : 0;
// }

int		to_c(char *buf, int *dir, va_list ap)
{
	char	*str;
	char	fill;

	str = buf;
	fill = ' ';
	WIDTH--;
	if (PRECISION == -1 && ZERO == 1)
		fill = '0';
	if (LEFT != 1)
		while (0 < WIDTH--)
			*str++ = fill;
	if (SPECIFIER == -1)
		*str++ = '\0';
	else
		*str++ = (SPECIFIER == 8) ? '%' : va_arg(ap, int);
	while (0 < WIDTH--)
		*str++ = ' ';
	return SPECIFIER == -1 ? (str - buf - 1) : (str - buf);
}

int		to_s(char *buf, int *dir, va_list ap)
{
	char	*str;
	char	*s;
	char	fill;
	int		len;
	int		i;

	s = va_arg(ap, char *);
	len = ft_strnlen(s, PRECISION);
	fill = ' ';
	if (ZERO == 1)
		fill = '0';
	str = buf;
	i = -1;
	if (LEFT != 1)
		while (len < WIDTH--)
			*str++ = fill;
	while (++i < len)
		*str++ = *s++;
	while (len < WIDTH--)
		*str++ = ' ';
	return (str - buf);
}

char	*ft_itoa_base(unsigned long nbr, unsigned int base, int x, int prec)
{
	char	*xbase;
	int		i;
	char	*n;

	i = 0;
	if (!(n = (char *)malloc(40)))
		return (NULL);
	xbase = (x == 0) ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nbr == 0 && prec != 0)
		n[i++] = '0';
	while (nbr != 0)
	{
		n[i++] = xbase[nbr % base];
		nbr = nbr / base;
	}
	n[i] = '\0';
	return (n);
}

char	*ft_number_str(char *n, char *buf, char sign, int *dir)
{
	char	fill;
	char	*str;
	int		len;

	str = buf;
	len = ft_strnlen(n, -1);
	if (LEFT != 1 && (ZERO != 1 || PRECISION != -1))
		while (0 < WIDTH--)
			*str++ = ' ';
	if (sign != 0)
		*str++ = sign;
	if (SPECIFIER == 2 || (SPECIAL == 1 && SPECIFIER >= 6 && SPECIFIER <= 7))
	{
		*str++ = '0';
		*str++ = (SPECIFIER == 6) ? 'X' : 'x';
	}
	fill = (ZERO == 1) ? '0' : ' ';
	if (LEFT != 1)
		while (0 < WIDTH--)
			*str++ = fill;
	while (PRECISION-- > len)
		*str++ = '0';
	while (n && len-- > 0)
		*str++ = n[len];
	return (str);
}

int		get_nbr()

int		to_nbr(char *buf, int *dir, va_list ap)
{
	long	nbr;
	char	sign;
	char	*n;

	nbr = get_nbr(dir, ap);
	sign = (SPACE == 1) ? ' ' : 0;
	sign = (PLUS == 1) ? '+' : sign;
	sign = (nbr < 0) ? '-' : sign;
	sign = (SPECIFIER == 3 || SPECIFIER == 4) ? sign : 0;
	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	(SPECIFIER == 2 || SPECIAL == 1) ? WIDTH = WIDTH - 2 : 0;
	if (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2)
		n = ft_itoa_base((unsigned long)nbr, 16, 7 - SPECIFIER, PRECISION);
	else
		n = ft_itoa_base((unsigned long)nbr, 10, 0, PRECISION);
	PRECISION = PRECISION < ft_strnlen(n, -1) ? ft_strnlen(n, -1) : PRECISION;
	WIDTH = WIDTH - PRECISION;
	return (ft_number_str(n, buf, sign, dir) - buf);
}
// int		to_nbr(char *buf, int *dir, va_list ap)
// {
// 	long	nbr;
// 	char	sign;
// 	char	*n;
//
// 	if (SPECIFIER == 2)
// 		nbr = (unsigned long)va_arg(ap, void *);
// 	else if (SPECIFIER == 5)
// 		nbr = (unsigned long)va_arg(ap, unsigned int);
// 	else
// 		nbr = (long)va_arg(ap, int);
// 	sign = (SPACE == 1) ? ' ' : 0;
// 	sign = (PLUS == 1) ? '+' : sign;
// 	sign = (nbr < 0) ? '-' : sign;
// 	sign = (SPECIFIER == 3 || SPECIFIER == 4) ? sign : 0;
// 	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
// 	(SPECIFIER == 2 || SPECIAL == 1) ? WIDTH = WIDTH - 2 : 0;
// 	if (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2)
// 		n = ft_itoa_base((unsigned long)nbr, 16, 7 - SPECIFIER, PRECISION);
// 	else
// 		n = ft_itoa_base((unsigned long)nbr, 10, 0, PRECISION);
// 	PRECISION = PRECISION < ft_strnlen(n, -1) ? ft_strnlen(n, -1) : PRECISION;
// 	WIDTH = WIDTH - PRECISION;
// 	return (ft_number_str(n, buf, sign, dir) - buf);
// }

int		ft_cont(char *buf, const char **format, va_list ap, int i)
{
	int		dir[11];

	while (i > 0)
		dir[--i] = -1;
	while (**format && i < BUFF_SIZE)
	{
		if (**format != '%')
			buf[i++] = *(*format)++;
		else
		{
			(*format)++;
			ft_initdir(dir, format, ap);
			ft_specifier(dir, format);
			// printf("0:%d | 1: %d |   2: %d | 3 : %d | 4 : %d | 5 : %d | 6  : %d | 7 : %d | 8 : %d\n", dir[0], dir[1], dir[2], dir[3], dir[4], dir[5], dir[6], dir[7], dir[8]);
			if (SPECIFIER < 1 || SPECIFIER == 8)
				i += to_c(&buf[i], dir, ap);
			else if (SPECIFIER == 1)
				i += to_s(&buf[i], dir, ap);
			else if (SPECIFIER > 1 && SPECIFIER < 8)
				i += to_nbr(&buf[i], dir, ap);
		}
		if (*(*format - 1) == '\n')
			return (i);
	}
	buf[i] = '\0';
	return (i);
}

int			ft_printf(const char *format, ...)
{
	char	buf[BUFF_SIZE];
	va_list	ap;
	int		printed;
	int		last;

	if (format == NULL)
		return (-1);
	printed = 0;
	va_start(ap, format);
	while (*format)
	{
		last = ft_cont(buf, &format, ap, 11);
		write(1, buf, last);
		printed += last;
	}
	va_end(ap);
	return (printed);
}

int		 main(void)
{
	char	var;

	// var = 'c';
	// printf("RETURN: %d\n", ft_printf("%20%\n", 'f'));
	// printf("RETURN: %d\n", printf("%20%\n", 'f'));
	printf("RETURN: %d\n", ft_printf("%20l\n", 'f'));
	printf("RETURN: %d\n", printf("%20l\n", 'f'));
	// printf("RETURN: %d\n", ft_printf("[%c]\n", 'r'));
	// printf("RETURN: %d\n", printf("[%20c]\n", 'r'));
	// printf("RETURN: %d\n", ft_printf("PRINT [%p]\n", &var));
	// printf("RETURN: %d\n", printf("PRINT [%p]\n", &var));
	// printf("RETURN: %d\n", ft_printf("PRINT [%.20u]\n", 4111));
	// printf("RETURN: %d\n", printf("PRINT [%.20u]\n", 4111));
	// printf("RETURN: %d\n", ft_printf("PRINT [%#20X]\n", 111));
	// printf("RETURN: %d\n", printf("PRINT [%#20X]\n", 111));
	// printf("RETURN: %d\n", ft_printf("PRINT [%++0.ii]\n", 1));
	// printf("RETURN: %d\n", printf("PRINT [%+0.i]\n", 1));
	// printf("RETURN: %d\n", ft_printf("[%c]\n", '\0'));
	// printf("RETURN: %d\n", printf("[%c]\n", '\0'));
	// ft_printf("[%c]\n", 'c');
	// printf("[%c]\n", 'c');
	// ft_printf("%-20c]\n", '\0');
	// printf("%-20c]\n", '\0');
	//
	// printf("%-20s|\n", "Vad");
	// ft_printf("heeeeej\n");
	// ft_printf("heeeeej %40 .3 s\n", "TEseeeeert");
	// ft_printf("[%20.0md]\n", 0);
	// printf("[%20.0md]\n", 0);
	// ft_printf("%.d\n", 1);
	// printf("[%.d]\n", 1);
	return (0);
}
