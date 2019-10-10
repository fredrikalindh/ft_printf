/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:52:53 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/10 18:47:39 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	ap;

	i = -1;
	a_count = 0;
	va_start(ap, format);
	i = 0;
	j = 0;
	while (format[++i])
	{
		write(1, &format[i], 1);
		if (format[i] == '%')
		{
			ft_directive(&format[i], va_arg[j]);
			j++;
		}
	}
	write(1, "\n", 1);
	va_end(ap);
}
