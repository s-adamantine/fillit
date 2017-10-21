/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:10:14 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/17 19:55:23 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# define VALID_CHAR(x) (x == '.' || x == '#')
# define BUF_SIZE 546

# include <fcntl.h> //open
# include <stdlib.h>
# include <stdio.h> //DELETE before submission
# include "../libft/libft.h"

typedef struct	s_tetri
{
	int			m;
	char		letter;
	char		*str;
}				t_tetri;

typedef struct	s_map
{
	int			m;
	int			size;
	char		*str;
}				t_map;

int				parse_tetrimino_file(int fd, char *buf);
t_tetri			**insert_array(char *buf);
void			solve_smallest_square(t_tetri *tetriminos, t_map *map);
char			**valid_tetriminos(void);
char			*reduce_tetrimino(char *t);
t_map			*solve_entry(t_tetri **tetriminos);

#endif
