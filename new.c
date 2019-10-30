/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:37:08 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/30 13:27:31 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	skip_atoi(const char **s)
{
	int		nb;

	nb = 0;
	while (**s >= '0' && **s <= '9')
		nb = nb * 10 + *((*s)++) - '0';
	return (nb);
}

static int	ft_iscspec(const char c)
{
	int		i;

	i = -1;
	while (C_SPEC[++i])
		if (C_SPEC[i] == c)
			return (i);
	return (0);
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

void	ft_initdir(int *dir, const char **format, va_list ap)
{
	while (**format && !(ft_iscspec(**format)))
	{
		if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		else if (**format == '*')
		{
			WIDTH = va_arg(ap, int);
			if (WIDTH < 0 && (LEFT = 1) == 1)
				WIDTH = WIDTH * -1;
		}
		if (**format == '.' && (*format)++ != NULL)
		{
			if (**format >= '1' && **format <= '9')
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
		(*format)++;
	}
	SPECIFIER = ft_iscspec(*((*format)++));
}

int		to_c(char *buf, int *dir, va_list ap)
{
	char	*str;
	int		width;
	char	fill;

	str = buf;
	fill = (ZERO == 1) ? '0' : ' ';
	if (LEFT != 1)
		while (0 < WIDTH--)
			*str++ = fill;
	*str++ = (SPECIFIER == 8) ? '%' : va_arg(ap, int);
	while (0 < WIDTH--)
		*str++ = ' ';
	return (str - buf);
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
	fill = (ZERO == 1) ? '0' : ' ';
	str = buf;
	printf("%s\n", s);
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

char	*ft_itoa_base(unsigned long nbr, int base, int x)
{
	char	*xbase;
	int		i;
	char	*n;

	i = 0;
	if (!(n = (char *)malloc(40)))
		return (NULL);
	xbase = (x == 1) ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nbr == 0)
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
		*str++ = (SPECIFIER != 6) ? 'X' : 'x';
	}
	fill = (ZERO == 1) ? '0' : ' ';
	if (LEFT != 1)
		while (0 < WIDTH--)
			*str++ = fill;
	while (PRECISION < len)
		*str++ = '0';
	while (n && *n)
		*str++ = *n++;
	n != NULL ? free(n) : 0;
	return (str);
}

int		to_nbr(char *buf, int *dir, va_list ap)
{
	long	nbr;
	char	sign;
	char	*n;

	if (SPECIFIER == 2)
		nbr = (long)va_arg(ap, void *);
	else
		nbr = (long)va_arg(ap, int);
	sign = (nbr < 0) ? '-' : 0;
	sign = (PLUS) ? '+' : sign;
	sign = (SPACE) ? ' ' : sign;
	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	if (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2)
		n = ft_itoa_base((unsigned)nbr, 16, 7 - SPECIFIER);
	else
		n = ft_itoa_base((unsigned)nbr, 10, 0);
	PRECISION = PRECISION < ft_strnlen(n, -1) ? ft_strnlen(n, -1) : PRECISION;
	WIDTH = WIDTH - PRECISION;
	return (ft_number_str(n, buf, sign, dir) - buf);
}

int		ft_cont(char *buf, const char *format, va_list ap)
{
	int		dir[9];
	int		i;

	i = 9;
	while (i > 0)
		dir[--i] = -1;
	while (*format && i < BUFF_SIZE - 40)
	{
		if (*format != '%')
			buf[i++] = *format++;
		else
		{
			format++;
			ft_initdir(dir, &format, ap); // SECURE ?
			// printf("0:%d | 1: %d |   2: %d | 3 : %d | 4 : %d | 5 : %d | 6  : %d | 7 : %d | 8 : %d\n", dir[0], dir[1], dir[2], dir[3], dir[4], dir[5], dir[6], dir[7], dir[8]);
			if (SPECIFIER == 0 || SPECIFIER == 8)
				i += to_c(&buf[i], dir, ap);
			else if (SPECIFIER == 1)
				i += to_s(&buf[i], dir, ap);
			else if (SPECIFIER > 1 && SPECIFIER < 8)
				i += to_nbr(&buf[i], dir, ap);
		}
	}
	buf[i] = '\0';
	return (i);
}

int			ft_printf(const char *format, ...)
{
	char	buf[BUFF_SIZE];
	va_list	ap;
	int		printed;

	if (format == NULL)
		return (-1);
	printed = 0;
	va_start(ap, format);
	printed = ft_cont(buf, format, ap);
	write(1, buf, printed);
	va_end(ap);
	return (printed);
}

int		 main(void)
{
	ft_printf("heeeeej\n");
	ft_printf("heeeeej %40 .3 s\n", "TEseeeeert");
	return (0);
}
