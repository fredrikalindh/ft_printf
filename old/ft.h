/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/02 16:53:11 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

# define BUFF_SIZE 10241
# define C_SPEC "cspdiuxX%"
# define ALLOWED (**format == '0' || **format == '-' || **format == '\'' || \
**format == ' ' || **format == '+' || **format == '#' || **format == '*' || \
**format == '.' || (**format >= '0' && **format <= '9')) 
// || **format == 'h' || \
// **format == 'l')

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

#endif