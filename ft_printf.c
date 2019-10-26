/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredrika <fredrika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 12:58:06 by fredrika          #+#    #+#             */
/*   Updated: 2019/10/25 23:20:03 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

static int skip_atoi(const char **s)
{
	int		i;

	i = 0;
	while (isdigit(**s))
		i = i * 10 + *((*s)++) - '0';
	return (i);
}

static int	ft_iscspec(const char c)
{
	int		i;

	i = -1;
	while (C_SPEC[++i])
		if (C_SPEC[i] == c)
			return (i);
	return (0);
}

static void	ft_initdir(int **dir, char **format, va_list ap)
{
	while (!(ft_iscspec(**format)))
	{
		if (**format == '0')
			*ZERO = 1;
		if (**format == '-')
			*LEFT = 1;
		if (**format >= '1' && **format <= '9')
			*WIDTH = skip_atoi(format);
		else if (**format++ == '*')
			*WIDTH = va_arg(ap, int);
		if (*WIDTH < 0 && (LEFT = 1) == 1)
			*WIDTH = *WIDTH * -1;
		if (**format++ == '.')
		{
			if (**format >= '1' && **format <= '9')
				*PRECISION = skip_atoi(format);
			else if (**format++ == '*')
				*PRECISION = va_arg(ap, int);
			if (*PRECISION < 0)
				*PRECISION = 0;
		}
		*format++; // ??
	}
	SPECIFIER = ft_iscspec(**format);
	*format++;
}

static int	ft_goto_c(char *buf, int dir, va_list ap)
{
	char	*str;
	int		width;

	width = WIDTH;
	if (!(LEFT == 1)
		while (0 < width--)
			*str++ = ' ';
	*str++ = va_arg(ap, char);
	while (0 < width--)
		*str++ = ' ';
	return (buf - str);
}

static int	ft_cont(char *buf, const char *format, va_list ap)
{
	int		dir[7];
	int		i;

	i = 7;
	while (--i > 0)
		dir[i] = -1;
	while (*format != '\0' && i < BUFF_SIZE)
	{
		if (*format == '%')
		{
			ft_initdir(&dir, &format, ap);
			i = ft_goto[SPECIFIER](buf, dir, ap);
		}
		*buf++ = *format++;
		i++;
	}
	*buf = '\0';
	return (i);
}

int		ft_printf(char *format, ...)
{
	char	buf[BUFF_SIZE];
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_cont(buf, format, ap);
	va_end(ap);
	ft_putstr(buf, printed);
	return (printed);
}
