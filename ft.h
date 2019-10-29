/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/29 11:12:53 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 10240
# define C_SPEC "cspdiuxX%"
/* ------------- DIR[] ------------- */
# define ZERO 1 /* zero padding */
# define LEFT 2 /* left justify */
# define PLUS 4 /* sign = plus */
# define SPACE 8 /* sign = ' '*/
# define SMALL 16 /* use small chars for hexa */
# define SPECIAL 32 /* # */

typedef	struct		s_dir
{
	int flags;
	int width;
	int precision;
	int specifier;
	char fill;
	char sign;
}					t_dir;


#endif
