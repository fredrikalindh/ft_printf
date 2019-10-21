/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:09 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/18 13:54:36 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int		ft_iscspec(const char c)
{
	const char *c_spec;
	int i;

	i = 0;
	c_spec = C_SPEC;
	while (c_spec[i])
	{
		if (c_spec[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_initdir(int **dir, const char *format, va_list ap)
{
	int		i;

	i = -1;
	while (ft_iscspec(format[++i]) == 0)
	{
		if (format[i] == '-')
		dir[0] =  1;
		if (format[i] == '0')
			dir[1] = 1;
		if (format[i] >= '1' && format[i] <= '9')
			dir[2] = ft_atoi(&format[i]);
		while (format[i] >= '0' && format[i] <= '9') //inside if ?
				i++;
		if (format[i] == '*')
			dir[2] = va_arg(ap, int);
		if (format[i++] == '.')
		{
			if (format[i] >= '1' && format[i] <= '9')
				dir[3] = ft_atoi(&format[i]);
			else if (format[i] == '*')
				dir[3] = va_arg(ap, int);
			while (format[i] >= '0' && format[i] <= '9')
				i++;
		}
	}
}

char	*ft_putdi(char *nbr, int *dir, int len) // NOT DONE
{
	char	*str;
	int		i;
	int		start;
	int		dif;
	char	fill;

	if (!(str = (char *)malloc(sizeof(char) * (dir[2] + 1))))
		return (NULL);
	fill = dir[1] == 1 ? '0' : ' ';

	/*
	om 0 : overrides -, om neg nr -> minus före 0or, spelar bara roll m width
	om .0 -> 0 will give no input
	*/

}

int		to_di(const char *format, va_list ap) // NOT DONE
{
	int		nbr;
	int		dir[5];
	char	*str;
	int		len;

	len = -1;
	while (++len < 5)
		dir[len] = 0;
	ft_initdir(&dir, format, ap);
	nbr = va_arg(ap, int);
	str = ft_itoa(nbr);
	len = ft_strlen(str);
	dir[2] = len > dir[2] ? len : dir[2];
	dir[2] = dir[3] > dir[2] ? dir[3] : dir[2];
	dir[0] = dir[1] == 1 ? 0 : dir[0];
	ft_putdi(str, dir, len);
	len = ft_strlen(str);
	free(str);
	return (len);
}

char	*ft_putstr(char *s, int *dir, int len)
{
	char	*str;
	int		i;
	int		start;
	int		dif;

	dir[3] = dir[3] == 0 ? len : dir[3];
	dif = dir[2] > len ? dir[2] : len;
	dif = dif > dir[3] ? dir[3] : dif;
	if (!(str = (char *)malloc(sizeof(char) * (dif + 1))))
		return (NULL);
	start = 0;
	i = 0;
	if (dif == dir[2] && dir[0] == 1)
		start = dif - len;
	while (i < start)
		str[i] = ' ';
	i = -1;
	while (s[++i] && i < dif)
		str[start + i] = s[i];
	while (s[++i])
		str[start + i] = ' ';
	str[start + i] = '\0';
	return (str);
}

int		to_s(const char *format, va_list ap)
{
	char	*s;
	int		dir[4];
	int		len;

	dir[2] = 0;
	dir[3] = -1;
	ft_initdir(&dir, format, ap);
	s = va_arg(ap, char *);
	len = ft_strlen(s);
	s = ft_putstr(s, dir, len);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int		to_c(const char *format, va_list ap)
{
	char	c;
	int		dir[4];
	char	*str;
	int		len;

	dir[2] = 1;
	ft_initdir(&dir, format, ap);
	c = va_arg(ap, char);
	dir[3] = 0;
	str[0] = c;
	str[1] = '\0';
	len = ft_strlen(str);
	str = ft_putstr(str, dir, len);
	len = ft_strlen(str);
	free(str);
	return (len);
}

void	create_ft_ptr(int (*to_forward[9])(const char *, va_list))
{
	to_forward[0] = to_c;
	to_forward[1] = to_s;
	to_forward[2] = to_p;
	to_forward[3] = to_di;
	to_forward[4] = to_di;
	to_forward[5] = to_u;
	to_forward[6] = to_x;
	to_forward[7] = to_X; // olika?
	to_forward[8] = to_per;
}

int		ft_printf(const char *format, ...)
{
	int		char_count;
	va_list	ap;
	int		(*to_forward[9])(int *, va_list);

	create_ft_ptr(to_forward);
	va_start(format, ap);
	char_count = 0;
	while (*format != '\0')
	{
		if (*format++ == '%') // is this working ?
		{
			char_count += op[ft_iscspec(*format++)](format, ap);
			while(ft_iscspec(format) == -1)
				format++; // fix this !!
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
