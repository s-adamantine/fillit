# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 23:03:39 by rgaia             #+#    #+#              #
#    Updated: 2017/11/07 12:28:57 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c parse.c insert.c solve.c map.c fit.c tetrimino.c

FLAGS = -Wall -Wextra -Werror -L../libft/. -lft -o

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(NAME) $(SRC)

clean: ;

fclean: clean
		@rm -rf $(NAME)

re: fclean
	@make
