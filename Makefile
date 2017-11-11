# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 23:03:39 by rgaia             #+#    #+#              #
#    Updated: 2017/11/11 12:26:31 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBNAME = libft.a

SRC = fillit.c parse.c insert.c solve.c map.c fit.c tetrimino.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIB = -L./libft -lft
LIBDIR = libft/

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBDIR)
	@$(CC) -c $(FLAGS) $(SRC)
	@$(CC) -o $(NAME) $(LIB) $(OBJ)

clean:
	@rm -rf $(LIBDIR)/*.o
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIBDIR)/$(LIBNAME)

re: fclean
	@make
