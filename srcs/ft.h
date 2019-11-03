/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/03 14:54:23 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 10241
# define C_SPEC "cspdiuxX%"
# define FMT **format
# define FLG FMT == '0' || FMT == '-' || FMT == '\'' || FMT == ' ' || FMT == '.'
# define ALL FMT == '+' || FMT == '#' || FMT == '*' || (FMT > '0' && FMT < '9')

# define ZERO dir[0]
# define LEFT dir[1]
# define PLUS dir[2]
# define SPACE dir[3]
# define SMALL dir[4]
# define SPECIAL dir[5]
# define LONG dir[6]
# define SIGNED dir[7]
# define WIDTH dir[8]
# define PRECISION dir[9]
# define SPECIFIER dir[10]

int		ft_printf(const char *format, ...);
int		ft_strnlen(char *str, int n);
int		skip_atoi(const char **s);
int		to_c(char *buf, int *dir, va_list ap);
int		to_s(char *buf, int *dir, va_list ap);
int		to_nbr(char *buf, int *dir, va_list ap);

#endif
