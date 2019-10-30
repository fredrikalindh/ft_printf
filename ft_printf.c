/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:58:06 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/30 12:24:38 by frlindh          ###   ########.fr       */
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

static void	ft_initdir(int *dir, const char **format, va_list ap)
{
	while (**format != '\0' && !(ft_iscspec(**format)))
	{
		printf("1:%c\n", **format);
		if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		if (**format == '*')
		{
			WIDTH = va_arg(ap, int);
			if (WIDTH < 0 && (LEFT = 1) == 1)
				WIDTH = WIDTH * -1;
		}
		printf("3:%s\n", *format);
		if (*((*format)++) == '.')
		{
			printf("2:%c}\n", **format);
			if (**format >= '1' && **format <= '9')
				PRECISION = skip_atoi(format);
			else if (*((*format)++) == '*')
				PRECISION = va_arg(ap, int);
			printf("P%d (%c)\n", PRECISION, **format);
			PRECISION = (PRECISION < 0) ? 0 : PRECISION;
		}
		printf("%c\n", **format);
		if (**format == '0')
			ZERO = 1;
		if (**format == '-')
			LEFT = 1;
		format++;
	}

	SPECIFIER = ft_iscspec(**format);
}

static int	to_c(char *buf, int *dir, va_list ap)
{
	char	*str;
	int		width;
	char	fill;

	width = WIDTH;
	str = buf;
	fill = (ZERO == 1) ? '0' : ' ';
	if (!(LEFT == 1))
		while (0 < width--)
			*str++ = fill;
	*str++ = (SPECIFIER == 8) ? '%' : va_arg(ap, int);
	while (0 < width--)
		*str++ = ' ';
	return (buf - str);
}

static int	to_s(char *buf, int *dir, va_list ap)
{
	char	*str;
	char	*s;
	int		len;
	int		i;

	s = va_arg(ap, char *);
	len = ft_strnlen(s, PRECISION);
	str = buf;
	if ((i = -1) == -1 && LEFT == -1)
		while (len < WIDTH--)
			*str++ = ' ';
	while (++i < len)
		*str++ = *s++;
	while (len < WIDTH--)
		*str++ = ' ';
	*str = '\0';
	return (buf - str);
}

char		*ft_itoa_base(char *n, long nbr, int base, int x)
{
	char	*xbase;
	int		i;

	i = 0;
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

char		*ft_number_str(char *n, int len, char sign, int *dir)
{
	char	fill;
	char	*str;
	int		i;

	i = 0;
	if (!(LEFT && (!(ZERO) || PRECISION)))
		while (0 < WIDTH--)
			str[i++] = ' ';
	if (sign != 0)
		str[i++] = sign;
//	if (base == 16 && (SPECIFIER == 2 || SPECIAL))
//	{
//		str[i++] = '0';
//		str[i++] = (SMALL == 0) ? 'X' : 'x';
//	}
	fill = (ZERO == 1) ? '0' : ' ';
	if (!(LEFT))
		while (0 < WIDTH--)
			str[i++] = fill;
	while (PRECISION < len)
		str[i++] = '0';
	while (*n)
		str[i++] = *n++;
	str[i] = '\0';
	return (str);
}

static char	*ft_numbers(char *str, long nbr, int base, int *dir)
{
	char	sign;
	char	*n;
	int		len;

	sign = (nbr < 0) ? '-' : 0;
	sign = (PLUS) ? '+' : sign;
	sign = (SPACE) ? ' ' : sign;
	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	n = ft_itoa_base(n, nbr, base, SMALL);
	len = ft_strnlen(n, -1);
	PRECISION = PRECISION < len ? len : PRECISION;
	WIDTH = WIDTH - PRECISION;
	n = ft_number_str(n, len, sign, dir);
	while (n && *n)
		*str++ = *n++;
	return (str);
}

static int	to_nbr(char *buf, int *dir, va_list ap)
{
	int		base;
	long	nbr;

	base = 10;
	if (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2) // == x || X
	{
		base = 16;
		SMALL = (SPECIFIER == 6) ? 1 : 0;
	}
	if (SPECIFIER == 2) // == p
	{
		WIDTH = (WIDTH == -1) ? 2 * sizeof(void) : WIDTH; // måste kolla upp
		ZERO = 1;
		nbr = (long)va_arg(ap, void *);
	}
	else
		nbr = (long)va_arg(ap, int);
	return (buf - ft_numbers(buf, nbr, base, dir));
}

// static void	create_ft_ptr(int (*to_forward[9])(char *, int *, va_list))
// {
// 	to_forward[0] = to_c;
// 	to_forward[1] = to_s;
// 	to_forward[2] = to_nbr;
// 	to_forward[3] = to_nbr;
// 	to_forward[4] = to_nbr;
// 	to_forward[5] = to_nbr;
// 	to_forward[6] = to_nbr;
// 	to_forward[7] = to_nbr; // olika?
// 	to_forward[8] = to_per;
// }

static int	ft_cont(char *buf, const char *format, va_list ap)
{
	int		dir[9];
	int		i;
	int		(*to_forward[9])(char *, int *, va_list);

	i = 9;
	while (i > 0)
		dir[--i] = -1;
//	create_ft_ptr(to_forward);
	printf("%d\n", i);
	while (*format != '\0' && i < BUFF_SIZE)
	{
		if (*format != '%')
			buf[i++] = *format++;
		else
		{
			format++;
			ft_initdir(dir, &format, ap);
			// printf("0:%d | 1:%d 2: %d 3: %d 4: %d 5: %d 6 : %d 7: %d 8: %d\n", dir[0], dir[1], dir[2], dir[3], dir[4], dir[5], dir[6], dir[7], dir[8]);
			if (SPECIFIER == 0 || SPECIFIER == 8)
				i += to_c(&buf[i], dir, ap);
			else if (SPECIFIER == 1)
				i += to_s(&buf[i], dir, ap);
			else
				i += to_nbr(&buf[i], dir, ap);
			// printf("%d!!\n", i);
		}
		// printf("I: %d [%s] BUF[%s]\n", i, format, buf);
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
	// while (format && *format && printed != BUFF_SIZE)
	printed = ft_cont(buf, format, ap);
	write(1, buf, printed);
	va_end(ap);
	return (printed);
}

ELLER :
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
	while (format && *format)
	{
		last = ft_cont(buf, format, ap);
		write(1, buf, last);
		printed += last;
	}
	va_end(ap);
	return (printed);
}

int		 main(void)
{
	ft_printf("heeeeej %.20s\n", "TEseeeeert");
	return (0);
}
