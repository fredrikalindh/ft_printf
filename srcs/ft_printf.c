/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:58:06 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/29 11:12:11 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int skip_atoi(const char **s)
{
	int		nb;

	nb = 0;
	while (**s >= '0' && **s <= '9'))
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

int		ft_strnlen(char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] && i < n)
		i++;
	return (i);
}

static void	ft_initdir(int *dir, const char **format, va_list ap)
{
	while (!(ft_iscspec(**format)) && **format)
	{
		if (**format == '0')
			ZERO = 1;
		if (**format == '-')
			LEFT = 1;
		if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		else if (*((*format)++) == '*')
			WIDTH = va_arg(ap, int);
		if (WIDTH < 0 && (LEFT = 1) == 1) // does this work to only set LEFT if first
			WIDTH = WIDTH * -1;
		if (*((*format)++) == '.')
		{
			if (**format >= '1' && **format <= '9')
				PRECISION = skip_atoi(format);
			else if (*((*format)++) == '*')
				PRECISION = va_arg(ap, int);
			if (PRECISION < 0)
				PRECISION = 0;
		}
		*format++; // ??
	}
	SPECIFIER = ft_iscspec(**format);
	return (dir);
}

static int	to_c(char *buf, int *dir, va_list ap)
{
	char	*str;
	int		width;

	width = WIDTH;
	str = buf;
	if (!(LEFT == 1)
		while (0 < width--)
			*str++ = ' ';
	*str++ = va_arg(ap, char);
	while (0 < width--)
		*str++ = ' ';
	return (buf - str);
}

static int	to_s(char *buf, int *dir, va_list ap)
{
	char	*str;
	char	*s;
	int		width;
	int		len;
	int		i;

	width = WIDTH;
	len = ft_strnlen(s, PRECISION);
	s = va_arg(ap, char *);
	if ((i = -1) == -1) && LEFT == -1)
		while (len < width--)
			*str++ = ' ';
	while (++i < len)
		*str++ = s++;
	while (len < width--)
		*str++ = ' ';
	return (buf - str);
}

static void	create_ft_ptr(int (*to_forward[9])(char *, int *, va_list))
{
	to_forward[0] = to_c;
	to_forward[1] = to_s;
	to_forward[2] = to_number;
	to_forward[3] = to_number;
	to_forward[4] = to_number;
	to_forward[5] = to_number;
	to_forward[6] = to_number;
	to_forward[7] = to_number; // olika?
	to_forward[8] = to_per;
}

char	*ft_itoa_base(char *n, long nbr, int base, int x)
{
	const char	xbase[16];
	int			i;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	xbase = (x == 0) ? "0123456789ABCDEF" : "0123456789abcdef";
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

char	*ft_number_str(char *n, int len, char sign, int *dir)
{
	int		i;
	char	fill;
	char	*str;

	if ((i = 0) == 0 && !(LEFT && !(ZERO) || PRECISION))
		while(0 < WIDTH--)
			str[i++] = ' ';
	if (sign != 0)
		str[i++] = sign;
	if (base == 16 && (SPECIFIER == 2 || SPECIAL))
	{
		str[i++] = '0';
		str[i++] = (SMALL == 0) ? 'X' : 'x';
	}
	fill = (ZERO == 1) ? '0' : ' ';
	if (!(LEFT))
		while (0 < WIDTH--)
			str[i++] = fill;
	while (PRECISION < ft_strnlen(n))
		str[i++] = '0';
	while (*n)
		str[i++] = *n++;
	str[i] = '\0';
	return (str);
}

static char	*ft_numbers(char *str, int nbr, int base, int *dir)
{
	char		sign;
	char		n[20];
	int			len;

	sign = (nbr < 0) ? '-' : 0;
	sign = (PLUS) ? '+' : SIGN;
	sign = (SPACE) ? ' ' : SIGN;
	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	n = ft_itoa_base(n, (long)nbr, base, SMALL);
	len = ft_strnlen(n, '\0');
	PRECISION = PRECISION < len ? len : PRECISION;
	WIDTH = WIDTH - PRECISION;
	str = ft_number_str(n, len, sign, dir);
	return (str);
}

static int	to_number(char *buf, int *dir, va_list ap)
{
	int		base;
	char	*str;
	char	*n;

	base = 10;
	str = buf;
	if (SPECIFIER == 6 || SPECIFIER == 7) // == x || X
	{
		base = 16;
		SMALL = SPECIFIER == 6 ? 1 : 0;
	}
	if (SPECIFIER == 2 && WIDTH == -1) // == p
	{
		WIDTH = 2 * sizeof(void); // måste kolla upp
		ZERO = 1;
		n = ft_itoa_base(n, (unsigned long)va_arg(ap, void *), 16, dir);
	}
	else
		n = ft_itoa_base(n, (unsigned long)va_arg(ap, int), 10, SMALL);
	str = ft_numbers(str, n, base, dir);
	return (buf - str);
}

static char	*ft_numbers(char *str, int nbr, int base, int *dir)
{
	char		sign;
	char		n[20];
	int			len;

	sign = (nbr < 0) ? '-' : 0;
	sign = (PLUS) ? '+' : SIGN;
	sign = (SPACE) ? ' ' : SIGN;
	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	n = ft_itoa_base(n, (long)nbr, base, SMALL);
	len = ft_strnlen(n, '\0');
	PRECISION = PRECISION < len ? len : PRECISION;
	WIDTH = WIDTH - PRECISION;
	str = ft_number_str(n, len, sign, dir);
	return (str);
}

static int	to_number(char *buf, int *dir, va_list ap)
{
	int		base;
	char	*str;
	char	*n;

	base = 10;
	str = buf;
	if (SPECIFIER == 6 || SPECIFIER == 7) // == x || X
	{
		base = 16;
		SMALL = (SPECIFIER == 6) ? 1 : 0;
	}
	if (SPECIFIER == 2 && WIDTH == -1) // == p
	{
		WIDTH = 2 * sizeof(void); // måste kolla upp
		ZERO = 1;
		n = ft_itoa_base(n, (unsigned long)va_arg(ap, void *), 16, dir);
	}
	else
		n = ft_itoa_base(n, (unsigned long)va_arg(ap, int), 10, SMALL);
	str = ft_numbers(str, n, base, dir);
	return (buf - str);
}

static int	ft_cont(char *buf, const char *format, va_list ap)
{
	int		dir[9];
	int		i;
	int		(*to_forward[9])(char *, int *, va_list);

	i = 8;
	while (i >= 0)
		dir[i--] = -1;
	create_ft_ptr(to_forward);
	while (*format != '\0' && i < BUFF_SIZE)
	{
		if (*format != '%')
			buf[i++] = *format++;
		dir = ft_initdir(dir, &format, ap);
		i += to_forward[SPECIFIER](&buf[i], dir, ap);
	}
	buf[i] = '\0';
	return (i);
}

int		ft_printf(const char *format, ...)
{
	char	buf[BUFF_SIZE];
	va_list	ap;
	int		printed;

	if (format == NULL)
		return (-1);
	printed = 0;
	va_start(ap, format);
//	while (format && *format && printed != BUFF_SIZE)
	printed = ft_cont(buf, format, ap);
	if (printed > 0)
		write(1, buf, printed);
	va_end(ap);
	return (printed);
}

int main()
{
	ft_printf("%s\n", "TEst");
	return (0);
}
