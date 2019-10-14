/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:52:53 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/14 16:47:27 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		doop(int (*op[9])(t_dir, va_list))  // create array of ftptrs
{
	op[0] = ft_putchar; // c
	op[1] = ft_putstr; // s w/ or w/out flags
	op[2] = ft_putnbr_hexa; // void*
	op[3] = ft_putnbr; // int arg, the precision, if any, gives the minimum number of digits that must appear
	op[4] = ft_putnbr; // int arg, the precision, if any, gives the minimum number of digits that must appear
	op[5] = ft_putnbr_un; // unsigned int
	op[6] = ft_putnbr_hexa;
	op[7] = ft_putnbr_hexa;
	op[8] = ft_putper;
}

int		ft_iscspec(char c)
{
	char *c_spec;
	int i;

	c_spec = C_SPEC;
	i = -1;
	while (c_spec[++i])
		if (c_spec[i] == c)
			return (i);
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

int		ft_conversion(t_dir dir, va_list ap)
{
	char	*spec;
	int		i;
	int		(*op[9])(t_dir, va_list);

	doop(op);
	spec = C_SPEC;
	i = -1;
	while (spec[++i])
	{
		if (dir->c_spec == spec[i])
		{
			doop[i](dir, ap);
			return (1);
		}
	}
	return (-1);
}

const char	*ft_directive(const char *format, t_dir *dir, va_list ap)
{
	int			i;
	static int	api;

	i = 0;
	api = 0;
	api++;
	if (format[i++] == '-')
		dir->min = 1;
	if (format[i++] == '0')
		dir->zero = 1;
	if (format[i] >= '1' && format[i] <= '9')
		dir->width = ft_atoi(&format[i]);
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	if (format[i++] == '*')
		dir->width = va_arg(ap, int);
	if (format[i++] == '.')
		dir->precision = ft_atoi(&format[i]);
	else if (format[i++] == '*')
		dir->precision = va_arg(ap, int);
	if ((dir->c_spec = ft_iscspec(format[i])) != -1)
			return(&format[i]);
	return (NULL);
}


int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_dir	dir;
	int		char_count;

	char_count = 0;
	ft_setupdir(&dir);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			format = ft_directive(format, &dir, ap);
			char_count = ft_conversion(dir, ap);
		}
		else
		{
			ft_putchar(*format);
			format++;
			char_count++;
		}
	}
	va_end(ap);
	return (char_count);
}
