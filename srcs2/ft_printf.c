/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:09 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/15 16:23:57 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"


char	*ft_putc(int *dir, va_list ap)
{
	char 			c;
	char			*str;
	unsigned int	i;
	char			fill;

	c = va_arg(ap, char);
	fill = ' ';
	if (dir[2] == 0)
		dir[2] = 1;
	if (!(str = (char *)malloc(sizeof(char) * (dir[2] + 1))))
		return (NULL);
	str[dir[2]] = '\0';
	if (dir[1] == 1)
		fill = '0';
	i = -1;
	while (str[++i])
		str[i] = fill;
	if (dir[0] == 1)
		str[0] = c;
	else
		str[i - 1] = c;
	return (str);
}

char	*ft_puts(int *dir, va_list ap)
{
	char	*s;
	char	*str;
	int		i;
	char	fill;

	s = va_arg(ap, char *);
	if (dir[3] == 0)
		dir[3] = ft_strlen(str);
	if (dir[2] < ft_strlen(str))
		dir[2] = ft_strlen(str);
	if (!(str = (char *)malloc(sizeof(char) * (dir[2] + 1))))
		return (NULL);
	fill = dir[1] == 1 ? '0' : ' ';
	i = -1;
	if (dir[0] == 0)
	{
		while (++i < (dir[2] - dir[3]))
			str[i] = fill;
	}
	while (++i < dir[3])
		str[i] = s[i];
	while (++i < dir[2])
		str[i] = fill;
	str[i] = '\0';
	return (str);
}

int		ft_nbrlen(int nbr)
{
	int len;
	int div;

	len = 11;
	div = 1000000000;
	if (nbr == 0)
		return (1);
	if (nbr > 0)
		len--;
	while (nbr / div == 0)
	{
		len--;
		div = div / 10;
	}
	return (len);
}

char	*ft_putp(int *dir, va_list ap)
{

}

char	*ft_putdi(int *dir, va_list ap)
{
	int		len;
	char	*str;
	int		num;

	num = va_arg(ap, int);

}

char	*ft_putu(int *dir, va_list ap)
{

}

char	*ft_putx(int *dir, va_list ap)
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

void	doop(char *(*op[9])(int *dir, va_list ap))
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
	if (*format++ == '-') // what if other order ?
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
	char	*(*op[9])(int *, va_list);
	char	*to_print;

	doop(op);
	va_start(format, ap);
	ft_initdir(&dir);
	char_count = 0;
	while (*format != '\0')
	{
		if (*format++ == '%')
		{
			format = ft_filldir(&dir, format, ap);
			to_print = op[dir[4]](dir, ap);
			ft_putstr(to_print);
			char_count += (to_print);
			free(to_print);
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



int		ft_printf(const char *format, ...)
{
	int		char_count;
	va_list	ap;
	char	*(*op[9])(int, va_list);

	doop(op);
	va_start(format, ap);
	char_count = 0;
	while (*format != '\0')
	{
		if (*format++ == '%')
		{
			while(ft_iscspec(format) == -1)
				format++;
			char_count += op[ft_iscspec(format++)](dir, ap); // send to get arg
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

int		main(int ac, char **av)
{
	ft_printf("Hejsan");

}
