/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:05:29 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/12 14:53:07 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void			ft_itoa_b(char *addr, unsigned long long nbr, int *dir)
{
	char			*xbase;
	int				i;
	char			n[70];
	int				base;

	i = 0;
	base = (SPECIFIER == 6 || SPECIFIER == 7 || SPECIFIER == 2) ? 16 : 10;
	xbase = (SPECIFIER == 7) ? "0123456789ABCDEF" : "0123456789abcdef";
	if (nbr == 0 && PRECISION != 0)
		n[i++] = '0';
	while (nbr != 0)
	{
		n[i++] = xbase[nbr % base]; // will itoa depending on base, since we don't know how long it will be, easier to make it reversed
		nbr = nbr / base;
	}
	n[i] = '\0';
	while (addr && --i >= 0) // and then reverse back when put it in the given string
		*addr++ = n[i];
	*addr = '\0'; // aaaaand null-terminate obv
}

static char			*ft_number_str(char *n, char *str, char sign, int *dir)
{
	int				len;

	len = ft_strnlen(n, -1); // get full len of nbr-str
	if (LEFT != 1 && ZERO != 1) // if no left and no zero, will print before sign
		while (0 < WIDTH--)
			*str++ = ' ';
	if (sign != 0) // if there's a sign, put it!
		*str++ = sign;
	if (SPECIFIER == 2 || (SPECIAL == 1 && SPECIFIER >= 6 && SPECIFIER <= 7)) // if p or special: put 0x
	{
		*str++ = '0';
		*str++ = (SPECIFIER == 7) ? 'X' : 'x';
	}
	if (LEFT != 1) //if left and zero-flag
		while (0 < WIDTH--)
			*str++ = '0';
	while (PRECISION-- > len) //precision bigger than len gives fill w 0
		*str++ = '0';
	while (n && *n && len-- > 0) //
		*str++ = *n++;
	while (0 < WIDTH--) // if no left-flag
		*str++ = ' ';
	return (str);
}

static long long	get_nbr(int *dir, va_list ap) // get nbr depending on specifier and length modifier
{
	if (SPECIFIER == 2)
		return ((unsigned long long)va_arg(ap, void *));
	else if (SPECIFIER == 5 || SPECIFIER == 6 || SPECIFIER == 7)
	{
		if (LONG == 0)
			return ((unsigned long long)va_arg(ap, unsigned long));
		else if (LONG == 1)
			return (va_arg(ap, unsigned long long));
		else if (SHORT == 0)
			return ((unsigned short int)va_arg(ap, unsigned int));
		else if (SHORT == 1)
			return ((unsigned char)va_arg(ap, unsigned int));
		else
			return ((unsigned long long)va_arg(ap, unsigned int));
	}
	if (LONG == 0)
		return ((long long)va_arg(ap, long));
	else if (LONG == 1)
		return ((long long)va_arg(ap, long long));
	else if (SHORT == 0)
		return ((short int)va_arg(ap, int));
	else if (SHORT == 1)
		return ((signed char)va_arg(ap, int));
	else
		return ((long long)va_arg(ap, int));
}

int					to_nbr(char *buf, int *dir, va_list ap)
{
	long long		nbr;
	char			sign;
	char			n[70];

	sign = 0;
	if (SPECIFIER == 3 || SPECIFIER == 4) //if d or i, nbr has to be fetch first in order to set sign
	{
		nbr = get_nbr(dir, ap);
		sign = (SPACE == 1) ? ' ' : 0;
		sign = (PLUS == 1) ? '+' : sign;
		sign = (nbr < 0) ? '-' : sign;
		WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	}
	if ((SPECIFIER == 3 || SPECIFIER == 4) && nbr >= 0) //if it was positive, send nbr to itoa
		ft_itoa_b(n, (unsigned long long)nbr, dir);
	else if (SPECIFIER == 3 || SPECIFIER == 4)
		ft_itoa_b(n, (unsigned long long)-nbr, dir); // to make the casting not fuck up, prob exists better way?
	else
		ft_itoa_b(n, (unsigned long long)get_nbr(dir, ap), dir); // if x, X, p, u just itoa the get_nbr
	PRECISION != -1 ? ZERO = -1 : 0; // precision overrides zero-flag
	PRECISION = PRECISION < ft_strnlen(n, -1) ? ft_strnlen(n, -1) : PRECISION; //prec fix-up so doesn't trunc nbr
	WIDTH = WIDTH - PRECISION; //width is minimal printed
	n[0] == '\0' || n[0] == '0' ? SPECIAL = -1 : 0; // if no number or 0: don't print 0x
	(SPECIFIER == 2 || SPECIAL == 1) ? WIDTH = WIDTH - 2 : 0; // if printing 0x -> remove 2 from width
	return (ft_number_str(n, buf, sign, dir) - buf); // send itoad str with dir to get formated str
}
