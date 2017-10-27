# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgaia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/11 23:03:39 by rgaia             #+#    #+#              #
#    Updated: 2017/10/26 23:37:54 by sadamant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c parse.c insert.c solve.c

FLAGS = -Wall -Wextra -Werror -L../libft/. -lft -o

all: $(NAME)

$(NAME):
		@gcc $(FLAGS) $(NAME) $(SRC)

clean: ;

fclean: clean
		@rm -rf $(NAME)

re: fclean
	@make
