/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:06:13 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/07 11:44:09 by fredrikalindh    ###   ########.fr       */
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

	s = va_arg(ap, char *);
	s == NULL ? s = NULLSTR : 0;
	len = ft_strnlen(s, PRECISION);
	fill = ' ';
	if (ZERO == 1)
		fill = '0';
	str = buf;
	i = -1;
	if (LEFT != 1)
		while (len < WIDTH--)
			*str++ = fill;
	while (s != NULL && ++i < len)
		*str++ = *s++;
	while (len < WIDTH--)
		*str++ = ' ';
	return (str - buf);
}
