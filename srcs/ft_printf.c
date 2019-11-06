/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:37:08 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/06 17:31:07 by frlindh          ###   ########.fr       */
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
		ZERO = (**format == '0') ? 1 : ZERO;
		LEFT = (**format == '-') ? 1 : LEFT;
		PLUS = (**format == '+') ? 1 : PLUS;
		SPACE = (**format == ' ') ? 1 : SPACE;
		SPECIAL = (**format == '#') ? 1 : SPECIAL;
		if (**format == '.' && (*format)++ != NULL)
		{
			if (**format >= '0' && **format <= '9')
				PRECISION = skip_atoi(format);
			else if (**format == '*' && (*format)++ != NULL)
				PRECISION = va_arg(ap, int);
			PRECISION = (PRECISION < 0) ? 0 : PRECISION;
		}
		else if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		else if (**format == '*' && (*format)++ != NULL)
		{
			WIDTH = va_arg(ap, int);
			if (WIDTH < 0 && (LEFT = 1) == 1)
				WIDTH = -WIDTH;
		}
		else
			(*format)++;
	}
}

static int	ft_cont(char *buf, const char **format, va_list ap, int i)
{
	int		dir[11];
	int		j;

	while (**format && i < BUFF_SIZE - 65)
	{
		if ((j = 11) == 11 && **format != '%')
			buf[i++] = *(*format)++;
		else
		{
			(*format)++;
			while (j > 0)
				dir[--j] = -1;
			ft_initdir(dir, format, ap);
			ft_specifier(dir, format);
			if (SPECIFIER < 1 || SPECIFIER == 8)
				i += to_c(&buf[i], dir, ap);
			else if (SPECIFIER == 1)
				i += to_s(&buf[i], dir, ap);
			else if (SPECIFIER > 1 && SPECIFIER < 8)
				i += to_nbr(&buf[i], dir, ap);
		}
		if (*(*format - 1) == '\n' && (buf[i] = '\0') == '\0')
			return (i);
	}
	return (buf[i] = '\0') == '\0' ? (i) : (i);
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
		last = ft_cont(buf, &format, ap, 0);
		write(1, buf, last);
		printed += last;
	}
	va_end(ap);
	return (printed);
}
