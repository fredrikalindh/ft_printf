/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:09 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/14 18:17:51 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"


const char	ft_putc(int *dir, va_list ap)
{
	const char c;

	c = va_arg(ap, const char);
	if (dir[2] != 0)
	if (dir[3] != 0)
	if (dir[0] == 1)
	if (dir[1] == 1)
	write(1, &c, 1);
	return (1);
}

const char	ft_puts(int *dir, va_list ap)
{
	const char *c;

	c = va_arg(ap, const char *);
	if (dir[2] != 0)
	if (dir[3] != 0)
	if (dir[0] == 1)
	if (dir[1] == 1)
	write(1, &c, 1);
	return (1);
}

const char	ft_putp(int *dir, va_list ap)
{

}

const char	ft_putdi(int *dir, va_list ap)
{

}

const char	ft_putu(int *dir, va_list ap)
{

}

const char	ft_putx(int *dir, va_list ap)
{
	long int	nbr2;
	char		*base;

	if (dir[4] == 6)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";

	nbr2 = va_arg(ap, long int);
	if (nbr2 < 0)
	{
		nbr2 = nbr2 * -1;
		ft_putchar('-');
	}
	if (nbr2 < 16)
		ft_putchar(base[nbr2]);
	if (nbr2 >= 16)
	{
		ft_putx(nbr2 / 16);
		ft_putchar(base[nbr2 % 16]);
	}
}

void	doop(const char *(*op[9])(int *dir, va_list ap))
{
	op[0] = ft_putc; // c
	op[1] = ft_puts; // s w/ or w/out flags
	op[2] = ft_putp; // void*
	op[3] = ft_putdi; // int arg, the precision, if any, gives the minimum number of digits that must appear
	op[4] = ft_putdi; // int arg, the precision, if any, gives the minimum number of digits that must appear
	op[5] = ft_putu; // unsigned int
	op[6] = ft_putx;
	op[7] = ft_put;
	op[8] = ft_putper;
}

int		ft_iscspec(const char c)
{
	const char *c_spec;
	int i;

	i = 0;
	c_spec = C_SPEC;
	while (c_spec[i])
	{
		if (c_spec[i] == c)
			return (i)
		i++;
	}
	return (-1);
}

void	ft_initdir(int *dir)
{
	int i;

	i = 0;
	while (i < 5)
		dir[i] = 0;
}

const char	*ft_filldir(int *dir, const char *format, va_list ap)
{
	if (*format++ == '-')
		dir[0] = 1;
	if (*format++ == '0')
		dir[1] = 1;
	if (*format >= 1 && *format <= 9)
	{
		dir[2] = ft_atoi(format);
		while (*format >= 0 && *format <= 9)
			format++;
	}
	else if (*format++ == '*')
		dir[2] = va_arg(ap, int);
	if (*format == '.')
		format++;
	if (*format >= 1 && *format <= 9)
	{
		dir[3] = ft_atoi(format);
		while (*format >= 0 && *format <= 9)
			format++;
	}
	else if (*format++ == '*')
		dir[3] = va_arg(ap, int);
	if (ft_iscspec(*format) != -1)
		dir[4] = ft_iscspec(*format);
	return (format);
}

int		ft_printf(const char *format, ...)
{
	int		char_count;
	int		dir[5];
	va_list	ap;
	int		(*op[9])(int *, va_list);

	doop(op);
	va_start(format, ap);
	ft_initdir(&dir);
	char_count = 0;
	while (*format != '\0')
	{
		if (*format++ == '%')
		{
			format = ft_filldir(&dir, format, ap);
			ft_putstr(op[dir[4]], ap);
			char_count(ft_strlen(op[dir[4]], ap));
		}
		else
		{
			ft_putchar(*format++);
			char_count++;
		}
	}
	va_end(ap);
	return (char_count);
}
