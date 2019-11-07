/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:06:37 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/07 11:42:43 by fredrikalindh    ###   ########.fr       */
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
	return (SPECIFIER == -1) ? (str - buf - 1) : (str - buf);
}
