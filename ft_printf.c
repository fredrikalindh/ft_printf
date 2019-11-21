/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:37:08 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/12 14:05:42 by frlindh          ###   ########.fr       */
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

static void	ft_specifier(int *dir, const char **format, int i, va_list ap)
{
	while (**format == 'h' || **format == 'l')
	{
		if (**format == 'l')
			LONG++;
		if (**format == 'h')
			SHORT++;
		(*format)++;
	}
	(SPECIFIER = ft_iscspec(**format)) >= 0 ? (*format)++ : 0;
	if (SPECIFIER == 9)
		to_n(i, dir, ap);
}

static void	ft_initdir(int *dir, const char **format, va_list ap)
{
	while (ALL || FLG) //while allowed chars
	{
		ZERO = (**format == '0') ? 1 : ZERO;
		LEFT = (**format == '-') ? 1 : LEFT;
		PLUS = (**format == '+') ? 1 : PLUS;
		SPACE = (**format == ' ') ? 1 : SPACE;
		SPECIAL = (**format == '#') ? 1 : SPECIAL;
		if (**format == '.' && (*format)++ != NULL)
		{
			if (**format >= '0' && **format <= '9')
				PRECISION = skip_atoi(format); //skip atoi skips format nbrs and returns as int
			else if (**format == '*' && (*format)++ != NULL)
				PRECISION = va_arg(ap, int);
			PRECISION = (PRECISION < 0) ? 0 : PRECISION;
		}
		else if (**format >= '1' && **format <= '9')
			WIDTH = skip_atoi(format);
		else if (**format == '*' && (*format)++ != NULL)
		{
			WIDTH = va_arg(ap, int);
			WIDTH < 0 ? SETWIDTH : 0;
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
		if ((j = 11) == 11 && **format != '%') // if no %, just copies to buf
			buf[i++] = *(*format)++;
		else
		{
			(*format)++; // go past %
			while (j > 0) // set all ints in dir to -1
				dir[--j] = -1;
			ft_initdir(dir, format, ap); //initialize dir w flags, width, precision
			ft_specifier(dir, format, i, ap); // add for h, l and specifier, and if n: sets pointer to i
			if (SPECIFIER < 1 || SPECIFIER == 8) // if c or % or no specifier
				i += to_c(&buf[i], dir, ap);
			else if (SPECIFIER == 1) // if s
				i += to_s(&buf[i], dir, ap);
			else if (SPECIFIER > 1 && SPECIFIER < 9) // if number (d, i, x, X, p)
				i += to_nbr(&buf[i], dir, ap);
		}
		if (*(*format - 1) == '\n') // if \n: \0 return -> print
			break;
	}
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
	while (*format) /* like the real printf mine prints when encountering a \n
	(or if near BUFF_SIZE) therefore a loop to finish *format, but usually enough w
	one ft_cont & one write */
	{
		last = ft_cont(buf, &format, ap, 0);
		write(1, buf, last);
		printed += last;
	}
	va_end(ap);
	return (printed);
}
