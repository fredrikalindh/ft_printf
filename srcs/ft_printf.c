/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:52:53 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/11 13:27:10 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

ft_directive(const char *format, va_list ap)
{
	int i;

	i = 0;
	if (format[i++] == '-')
		
	if (format[i++] == '0')

	if (format[i] >= '1' && format[i] <= '9')
	{
		width = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else if (format[i++] == '*')
		width = va_list++;
	if (format[i++] = '.')
		precision = ft_atoi(&format[i]);
	else if (format[i++] == '*')
		precision = va_list++;
	if (format[i] == 'c' && format[i] == 'p' && format[i] == 'p' &&
		format[i] == 'd' && format[i] == 'i' && format[i] == 'u' &&
		format[i] == 'x' && format[i] == 'X')
		ft_choose(ft_cmpconv(format[i]), width, precision, va_list);
	return (-1);
}


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
