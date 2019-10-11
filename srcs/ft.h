/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/11 16:59:54 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define C_SPEC = "cspdiuxX%"
# define TYPE = char **types;

types[0] = ""

typedef struct		s_dir
{
	int		min;
	int		zero;
	int		width;
	int		precision;
	char	c_spec;
}					t_dir;

int ft_printf(const char *, ...);
void ft_putchar(char c);
void ft_putnbr_hexa(int nbr);

#endif
