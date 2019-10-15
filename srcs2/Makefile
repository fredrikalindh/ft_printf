# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/08 14:20:33 by frlindh           #+#    #+#              #
#    Updated: 2019/10/15 15:36:23 by frlindh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME - COMPILATOR - FLAGS ************************************************** #
NAME			=	libftprintf.a
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

# INCLUDES ******************************************************************* #
INCLUDES_DIR	=	./includes

# SRCS *********************************************************************** #
SRCS_LIST		=
SRCS_DIR		=	srcs/
SRCS			=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

# OBJS *********************************************************************** #
OBJS_DIR		=	objs/
OBJS_LIST		=	$(patsubst %.c, %.o, $(SRCS_LIST))
OBJS			=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

# RULES ********************************************************************** #

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	$(GCC) $(FLAGS) -I $(INCLUDES_DIR) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
