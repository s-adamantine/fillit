/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:10:14 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/14 10:42:20 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FILLIT_H
# define __FILLIT_H
# define VALID_CHAR(x) (x == '.' || x == '#')
# define BUF_SIZE 546

# include <fcntl.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct	s_tet
{
	int			coord;
	int			height;
	int			width;
	char		letter;
	char		*str;
}				t_tet;

typedef struct	s_map
{
	int			m;
	int			ntet;
	int			size;
	char		*str;
}				t_map;

int				parse_tetrimino_file(int fd, char *buf);
int				fit_tetrimino(t_map *map, t_tet *tetrimino);
int				tet_width(char *t);
int				count_hash(char *t);
int				connections(char *t);
t_tet			**insert_array(char *buf);
void			clear_tetrimino(t_map *map, t_tet *tetrimino);
char			*reduce_tetrimino(char *t);
t_map			*solve(t_tet **tetriminos);
t_map			*expand_map(t_map *old_map);
t_map			*init_map(t_tet **tetriminos);
void			print_map(t_map *map);

#endif
