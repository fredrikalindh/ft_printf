/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 22:03:17 by fredrika          #+#    #+#             */
/*   Updated: 2019/11/03 22:48:18 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static void	ft_itoa_e(char *n, double nbr, int prec)
{
	int	e;
	double dec;

	dec = 0.0;
	while (nbr > 0 && prec-- > 0)
	{
		*n++ =
	}

}

int			*to_double(char *buf, int *dir, va_list ap)
{
	double	nbr;
	char	sign;
	char	n[70];

	nbr = va_arg(ap, double);
	sign = (SPACE == 1) ? ' ' : 0;
	sign = (PLUS == 1) ? '+' : sign;
	sign = (nbr < 0) ? '-' : sign;
	WIDTH = (sign != 0) ? WIDTH - 1 : WIDTH;
	if (SPECIFIER == 9)
		ft_itoa_e(n, nbr, PRECISION);
	PRECISION = -1 ? 6 : PRECISION;
	WIDTH = WIDTH - PRECISION;
}

// prec = chars after .
// if no prec -> will print 6 dec
// if prec = 0 -> no dec
// width = width - prec will give space before
//
