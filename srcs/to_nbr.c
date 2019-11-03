/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:05:29 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/03 12:13:54 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static char			*ft_itoa_b(long long nbr, int base, int x, int prec)
{
	char			*xbase;
	int				i;
	char			*n;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	if (!(n = (char *)malloc(70)))
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

static char			*ft_number_str(char *n, char *buf, char sign, int *dir)
{
	char			fill;
	char			*str;
	int				len;

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

static long long	get_nbr(int *dir, va_list ap)
{
	if (SPECIFIER == 2)
		return ((unsigned long long)va_arg(ap, void *));
	else if (SPECIFIER == 5)
	{
		if (LONG == 0)
			return ((unsigned long long)va_arg(ap, long));
		else if (LONG == 1)
			return ((unsigned long long)va_arg(ap, long long));
		else
			return ((unsigned long long)va_arg(ap, int));
	}
	else
	{
		if (LONG == 0)
			return ((long long)va_arg(ap, long));
		else if (LONG == 1)
			return ((long long)va_arg(ap, long long));
		else
			return ((long long)va_arg(ap, int));
	}
}

int					to_nbr(char *buf, int *dir, va_list ap)
{
	long long		nbr;
	char			sign;
	char			*n;

	sign = 0;
	if (SPECIFIER == 3 || SPECIFIER == 4)
	{
		nbr = get_nbr(dir, ap);
		sign = (SPACE == 1) ? ' ' : 0;
		sign = (PLUS == 1) ? '+' : sign;
		sign = (nbr < 0) ? '-' : sign;
		WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	}
	(SPECIFIER == 2 || SPECIAL == 1) ? WIDTH = WIDTH - 2 : 0;
	if (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2)
		n = ft_itoa_b((unsigned long long)get_nbr(dir, ap),
		16, 7 - SPECIFIER, PRECISION);
	else if (SPECIFIER == 5)
		n = ft_itoa_b((unsigned long long)get_nbr(dir, ap), 10, 0, PRECISION);
	else
		n = ft_itoa_b((unsigned long long)nbr, 10, 0, PRECISION);
	PRECISION = PRECISION < ft_strnlen(n, -1) ? ft_strnlen(n, -1) : PRECISION;
	WIDTH = WIDTH - PRECISION;
	return (ft_number_str(n, buf, sign, dir) - buf);
}
