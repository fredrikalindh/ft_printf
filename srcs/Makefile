# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:20:33 by frlindh           #+#    #+#              #
#    Updated: 2019/11/07 15:33:23 by fredrikalindh    ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPILATOR - FLAGS ************************************************** #
NAME			=	libftprintf.a
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

# SRCS *********************************************************************** #
SRCS			=	ft_printf.c ft_strnlen.c skip_atoi.c to_c.c to_s.c to_nbr.c

# OBJS *********************************************************************** #
OBJS		=	$(patsubst %.c, %.o, $(SRCS))

# RULES ********************************************************************** #

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) ft.h
	ar rcs $@ $^

bonus: $(NAME)

%.o: %.c
	$(GCC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
