/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:37:08 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/03 12:44:56 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int	ft_iscspec(const char c)
{
	int		i;

	i = -1;
	while (C_SPEC[++i])
		if (C_SPEC[i] == c)
			return (i);
	return (-1);
}

static void	ft_specifier(int *dir, const char **format)
{
	while (**format == 'h' || **format == 'l')
	{
		if (**format == 'h')
			SIGNED++;
		if (**format == 'l')
			LONG++;
		(*format)++;
	}
	(SPECIFIER = ft_iscspec(**format)) >= 0 ? (*format)++ : 0;
}

static void	ft_initdir(int *dir, const char **format, va_list ap)
{
	while (ALL || FLG)
	{
		if (**format == '.' && (*format)++ != NULL)
		{
			if (**format >= '0' && **format <= '9')
				PRECISION = skip_atoi(format);
			else if (**format == '*')
				PRECISION = va_arg(ap, int);
			PRECISION = (PRECISION < 0) ? 0 : PRECISION;
		}
		ZERO = (**format == '0') ? 1 : ZERO;
		LEFT = (**format == '-') ? 1 : LEFT;
		PLUS = (**format == '+') ? 1 : PLUS;
		SPACE = (**format == ' ') ? 1 : SPACE;
		SPECIAL = (**format == '#') ? 1 : SPECIAL;
		if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		else if (**format == '*')
		{
			WIDTH = va_arg(ap, int);
			if (WIDTH < 0 && (LEFT = 1) == 1)
				WIDTH = -WIDTH;
		}
		(*format)++;
	}
}

static int	ft_cont(char *buf, const char **format, va_list ap, int i)
{
	int		dir[11];

	while (i > 0)
		dir[--i] = -1;
	while (**format && i < BUFF_SIZE - 65)
	{
		if (**format != '%')
			buf[i++] = *(*format)++;
		else
		{
			(*format)++;
			ft_initdir(dir, format, ap);
			ft_specifier(dir, format);
			if (SPECIFIER < 1 || SPECIFIER == 8)
				i += to_c(&buf[i], dir, ap);
			else if (SPECIFIER == 1)
				i += to_s(&buf[i], dir, ap);
			else if (SPECIFIER > 1 && SPECIFIER < 8)
				i += to_nbr(&buf[i], dir, ap);
		}
		if (*(*format - 1) == '\n')
			return (i);
	}
	buf[i] = '\0';
	return (i);
}

int			ft_printf(const char *format, ...)
{
	char	buf[BUFF_SIZE];
	va_list	ap;
	int		printed;
	int		last;

	if (format == NULL)
		return (-1);
	printed = 0;
	va_start(ap, format);
	while (*format)
	{
		last = ft_cont(buf, &format, ap, 11);
		write(1, buf, last);
		printed += last;
	}
	va_end(ap);
	return (printed);
}
