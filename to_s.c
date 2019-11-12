/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:06:13 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/12 14:11:59 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			to_s(char *buf, int *dir, va_list ap)
{
	char	*str;
	char	*s;
	char	fill;
	int		len;
	int		i;

	s = va_arg(ap, char *); // fetch arg
	s == NULL ? s = NULLSTR : 0; // if no arg (=> null), str is set to "(null)"
	len = ft_strnlen(s, PRECISION); // get len: if no prec (-1), full len is returned
	fill = ' ';
	if (ZERO == 1) // if zero flag, put 0 first
		fill = '0';
	str = buf;
	i = -1;
	if (LEFT != 1)
		while (len < WIDTH--) //if not len and width exists, fill is put before s
			*str++ = fill;
	while (++i < len) // cpy s to buf
		*str++ = *s++;
	while (len < WIDTH--) // if left and width, fill with ' '
		*str++ = ' ';
	return (str - buf);
}
