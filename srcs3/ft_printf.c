/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:12:09 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/15 21:51:07 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_initdir(int *dir, const char *format)
{
	int		i;

	i = -1;
	while (format[++i] == '-' || format[i] == '0')
	{
		dir[0] = format[i] == '-' ? 1 : 0;
		dir[1] = format[i] == '0' ? 1 : 0;
	}
	if (format[i] >= '1' && format[i] <= '9')
		dir[2] = ft_atoi(&format[i]);
	else if (format[i++] == '*')
		dir[2] = va_arg(ap, int);
	while (format[i] >= '0' && format[i] <= '9') //inside if ?
			i++;
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

char	*ft_putdi(int di, int *dir) // NOT DONE
{
	char	*str;
	int		i;
	int		len;
	int		dif;

	len = ft_strnbr(di);
	if (dir[3] != -1 && dir[3] < len)
		len = dir[3];
	else if (dir[2] > len)
		len = dir[2];
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	dif = len > ft_strlen(s) ? len - ft_strlen(s) : 0;
	while (dir[0] == 0 && i < dif)
		str[i] = ' ';
	dif = i > 0 ? dif : 0;
	i = -1;
	while (s[++i])
		str[i + dif] = s[i];
	while (i <= len)
		str[dif + i++] = ' ';
	str[dif + i] = '\0';
	return (str);
}

int		to_di(const char *format, va_list ap) // NOT DONE
{
	int		di;
	int		dir[4];
	char	*str;
	int		len;

	i = -1;
	dir[2] = 0;
	dir[3] = -1;
	di = va_arg(ap, int);
	ft_initdir(&dir, format);
	str = ft_putdi(di, dir);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}


char	*ft_putp(char *s, int *dir) // NOT DONE
{
	char	*str;
	int		i;
	int		len;
	int		dif;


}

int		to_p(const char *format, va_list ap) // NOT DONE
{
	char	*s;
	int		dir[4];
	char	*str;
	int		len;

	i = -1;
	dir[2] = 0;
	dir[3] = -1;
	s = va_arg(ap, char *);
	ft_initdir(&dir, format);
	str = ft_puts(s, dir);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

char	*ft_puts(char *s, int *dir)
{
	char	*str;
	int		i;
	int		len;
	int		dif;

	len = ft_strlen(s);
	if (dir[3] != -1 && dir[3] < len)
		len = dir[3];
	else if (dir[2] > len)
		len = dir[2];
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	dif = len > ft_strlen(s) ? len - ft_strlen(s) : 0;
	while (dir[0] == 0 && i < dif)
		str[i] = ' ';
	dif = i > 0 ? dif : 0;
	i = -1;
	while (s[++i])
		str[i + dif] = s[i];
	while (i <= len)
		str[dif + i++] = ' ';
	str[dif + i] = '\0';
	return (str);
}

int		to_s(const char *format, va_list ap)
{
	char	*s;
	int		dir[4];
	char	*str;
	int		len;

	i = -1;
	dir[2] = 0;
	dir[3] = -1;
	s = va_arg(ap, char *);
	ft_initdir(&dir, format);
	str = ft_puts(s, dir);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

char	*ft_putc(char c, int *dir)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(char) * (dir[2] + 1))))
		return (NULL);
	i = 0;
	if (dir[0] == 0)
	{
		while (i + 1 < dir[2])
		{
			str[i] = ' ';
			i++;
		}
	}
	str[i] = c;
	while (str[++i] <= dir[2])
		str[i] = ' ';
	str[i] = '\0';
	return (str);
}

int		to_c(const char *format, va_list ap)
{
	char	c;
	int		dir[4];
	char	*str;
	int		len;

	i = -1;
	dir[2] = 1;
	dir[3] = 0;
	c = va_arg(ap, char);
	ft_initdir(&dir, format);
	str = ft_putc(c, dir);
	ft_putstr(str);
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
