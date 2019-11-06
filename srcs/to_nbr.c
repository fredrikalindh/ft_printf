/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:05:29 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/06 13:55:47 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void		ft_itoa_b(char *addr, long long nbr, int *dir)
{
	char		*xbase;
	int			i;
	char		n[70];
	int			base;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	base = (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2) ? 16 : 10;
	xbase = (SPECIFIER == 7) ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nbr == 0 && PRECISION != 0)
		n[i++] = '0';
	while (nbr != 0)
	{
		n[i++] = xbase[nbr % base];
		nbr = nbr / base;
	}
	n[i] = '\0';
	while (addr && --i >= 0)
		*addr++ = n[i];

	*addr = '\0';
}

static char			*ft_number_str(char *n, char *str, char sign, int *dir)
{
	char			fill;
	int				len;

	len = ft_strnlen(n, -1);
	if (LEFT != 1 && ZERO != 1)
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
	while (n && *n && len-- > 0)
		*str++ = *n++;
	while (0 < WIDTH--)
		*str++ = ' ';
	return (str);
}

static long long	get_nbr(int *dir, va_list ap)
{
	if (SPECIFIER == 2)
		return ((unsigned long long)va_arg(ap, void *));
	else if (SPECIFIER == 5)
	{
		if (LONG == 0)
			return ((unsigned long long)va_arg(ap, unsigned long));
		else if (LONG == 1)
			return (va_arg(ap, unsigned long long));
		else
			return ((unsigned long long)va_arg(ap, unsigned int));
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
	char			n[70];

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
	if (SPECIFIER == 3 || SPECIFIER == 4)
		ft_itoa_b(n, (unsigned long long)nbr, dir);
	else
		ft_itoa_b(n, (unsigned long long)get_nbr(dir, ap), dir);
	PRECISION = PRECISION < ft_strnlen(n, -1) ? ft_strnlen(n, -1) : PRECISION;
	WIDTH = WIDTH - PRECISION;
	return (ft_number_str(n, buf, sign, dir) - buf);
}
