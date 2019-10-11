/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:52:53 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/11 16:59:52 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

ft_iscspec(char c)
{
	char *c_spec;
	int i;

	c_spec = C_SPEC;
	i = -1;
	while (c_spec[++i])
		if (c_spec[i] == c)
			return (1);
	return (-1);
}

void	ft_setupdir(t_dir *dir)
{
	dir->min = 0;
	dir->zero = 0;
	dir->width = -1;
	dir->precision = -1;
	dir->c_spec = NULL;
}

void	ft_conversion(t_dir dir, va_list ap)
{
	if (dir->c_spec)
}

int		ft_directive(const char *format, t_dir *dir, va_list ap)
{
	int i;

	i = 0;
	if (format[i++] == '-')
		dir->min = 1;
	if (format[i++] == '0')
		dir->zero = 1;
	if (format[i] >= '1' && format[i] <= '9')
	{
		dir->width = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9')
			i++;
	}
	else if (format[i++] == '*')
		dir->width = va_arg(ap, int);
	if (format[i++] = '.')
		dir->precision = ft_atoi(&format[i]);
	else if (format[i++] == '*')
		dir->precision = va_arg(ap, int);
	if (ft_iscspec(format[i]))
		{
			dir->c_spec = format[i];
			return(1);
		}
	return (0);
}


int		ft_printf(const char *format, ...)
{
	int		i;
	int		j;
	va_list	ap;
	t_dir	dir;

	if (!(ft_setupdir(&dir)))
		return (-1);
	va_start(ap, format);
	i = -1;
	j = 0;
	while (format[++i])
	{
		write(1, &format[i], 1);
		if (format[i] == '%')
		{
			ft_directive(&format[i], &dir, ap);
			``
			ft_conversion(dir, ap);
			j++;
		}
	}
	write(1, "\n", 1);
	va_end(ap);
}
