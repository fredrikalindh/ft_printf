# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:20:33 by frlindh           #+#    #+#              #
#    Updated: 2019/11/06 16:51:40 by frlindh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPILATOR - FLAGS ************************************************** #
NAME			=	libftprintf.a
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

# SRCS *********************************************************************** #
SRCS			=	ft_printf.c ft_strnlen.c skip_atoi.c to_c.c to_s.c to_nbr.c
SRCS_BONUS 		=

# OBJS *********************************************************************** #
OBJS		=	$(patsubst %.c, %.o, $(SRCS))
OBJS_BONUS	=	$(patsubst %.c, %.o, $(SRCS_BONUS))

# RULES ********************************************************************** #

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) *.h
	ar rcs $@ $^

bonus: $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all
