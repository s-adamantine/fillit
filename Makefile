# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 23:03:39 by rgaia             #+#    #+#              #
#    Updated: 2017/11/21 14:49:55 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
LIBNAME = libft.a

SRC = fillit.c parse.c insert.c solve.c map.c fit.c tetrimino.c
OBJ = $(SRC:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

LIBDIR = libft/
LIBINC = $(LIBDIR)/includes
LIB = -L./$(LIBDIR) -lft

all: $(NAME)

$(NAME):
	@$(MAKE) -C $(LIBDIR)
	@$(CC) -c $(FLAGS) $(SRC) -I $(LIBINC) 
	@$(CC) -o $(NAME) $(LIB) $(OBJ)

clean:
	@$(MAKE) clean -C $(LIBDIR)
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(LIBDIR)/$(LIBNAME)

re: fclean all
