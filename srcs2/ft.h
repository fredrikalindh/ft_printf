/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/14 13:09:32 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define C_SPEC = "cspdiuxX%"
# define TYPE = char **types;

typedef struct		s_dir
{
	int			min;
	int			zero;
	int			width;
	int			precision;
	char		c_spec;
}					t_dir;

int			ft_printf(const char *, ...);
void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_putnbr(int n);
void		ft_putnbr_hexa(int nbr);
int			ft_atoi(const char *str);
void		doop(int (*op[9])(t_dir, va_list));
int			ft_iscspec(char c);
void		ft_setupdir(t_dir *dir);
int			ft_conversion(t_dir dir, va_list ap);
const char	*ft_directive(const char *format, t_dir *dir, va_list ap);
int			main();


#endif
