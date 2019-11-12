/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:06:37 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/12 14:08:59 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			to_c(char *buf, int *dir, va_list ap)
{
	char	*str;
	char	fill;

	str = buf;
	fill = ' ';
	WIDTH--;
	if (PRECISION == -1 && ZERO == 1) // if zero flag is set and no precision if fills w 0, else ' '
		fill = '0';
	if (LEFT != 1) // if not left flag: width comes first
		while (0 < WIDTH--)
			*str++ = fill;
	if (SPECIFIER == -1) // if no specifier put \0
		*str++ = '\0';
	else
		*str++ = (SPECIFIER == 8) ? '%' : va_arg(ap, int); // if % put % else put arg char
	while (0 < WIDTH--) // if left, there is still width -> put ' '
		*str++ = ' ';
	return (SPECIFIER == -1) ? (str - buf - 1) : (str - buf); /* diff between
	address of buf and str gives how many chars were added */
}
