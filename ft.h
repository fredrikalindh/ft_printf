/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/26 19:46:50 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 1024
# define C_SPEC "cspdiuxX%"
/* ------------- DIR[] ------------- */
# define ZERO dir[0] /* zero padding */
# define LEFT dir[1] /* left justify */
# define PLUS dir[2] /* sign = plus */
# define SPACE dir[3] /* sign = ' '*/
# define SMALL dir[4] /* use small chars for hexa */
# define SPECIAL dir[5] /* # */
# define WIDTH dir[6] /* field width */
# define PRECISION dir[7]
# define SPECIFIER dir[8]


/* ---------- ALTERNATIVE ----------

typedef	struct		s_dir
{
	int flags;
	int width;
	int precision;
	int specifier;
}					t_dir;

# define FLAGS t_dir->flags
# define WIDTH t_dir->width
# define PRECISION t_dir->precision
# define SPECIFIER t_dir->specifier

----------------------------------- */


#endif
