/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/06 17:17:03 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

# define BUFF_SIZE 10241
# define C_SPEC "cspdiuxX%o"
# define NULLSTR "(null)"
# define FMT **format
# define FLG FMT == '0' || FMT == '-' || FMT == '\'' || FMT == ' ' || FMT == '.'
# define ALL FMT == '+' || FMT == '#' || FMT == '*' || (FMT > 47 && FMT < 58)

# define ZERO dir[0]
# define LEFT dir[1]
# define PLUS dir[2]
# define SPACE dir[3]
# define SMALL dir[4]
# define SPECIAL dir[5]
# define LONG dir[6]
# define WIDTH dir[7]
# define PRECISION dir[8]
# define SPECIFIER dir[9]

int		ft_printf(const char *format, ...);
int		ft_strnlen(char *str, int n);
int		skip_atoi(const char **s);
int		to_c(char *buf, int *dir, va_list ap);
int		to_s(char *buf, int *dir, va_list ap);
int		to_nbr(char *buf, int *dir, va_list ap);

#endif
