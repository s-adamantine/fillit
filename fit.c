/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:16:09 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/11 12:04:47 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check if the tetrimino would fit at the map at m
** m iterates through map, t iterates through tetrimino
** at t = 4, m would offset to account for different map sizes
*/

static int		check_fit(t_map *map, t_tet *tetrimino)
{
	int	m;
	int	t;

	t = 0;
	m = map->m;
	while (tetrimino->str[t])
	{
		if (t != 0 && t % 4 == 0)
			m = m + (map->size) - 4;
		if (tetrimino->str[t++] == '#')
		{
			if (map->str[m] == '.')
				m++;
			else
				return (0);
		}
		else
			m++;
	}
	tetrimino->coord = map->m;
	return (1);
}

/*
** copies out the tetrimino to the map at the m where check_fit succeds
*/

static void		insert_tetrimino(t_map *map, t_tet *tetrimino)
{
	int	t;
	int	m;

	t = 0;
	m = tetrimino->coord;
	while (tetrimino->str[t])
	{
		if (t != 0 && t % 4 == 0)
			m = m + (map->size) - 4;
		if (tetrimino->str[t++] == '#')
			(map->str)[m] = tetrimino->letter;
		m++;
	}
}

/*
** clear previous tet
*/

void			clear_tetrimino(t_map *map, t_tet *tetrimino)
{
	int t;
	int m;

	t = 0;
	m = tetrimino->coord;
	while (tetrimino->str[t])
	{
		if (t != 0 && t % 4 == 0)
			m = m + (map->size) - 4;
		if (tetrimino->str[t] == '#')
		{
			(map->str)[m] = '.';
		}
		m++;
		t++;
	}
}

/*
** iterates through map and calls check_fit at every m, if check_fit
** works, copies out tetrimino to the map, else increments m until
** it finds a fit.
*/

int				fit_tetrimino(t_map *map, t_tet *tetrimino)
{
	int last_m;

	last_m = (int)ft_strlen(map->str) - (int)ft_strlen(tetrimino->str);
	map->m = tetrimino->coord + 1;
	while (map->m <= last_m)
	{
		if (map->m % map->size > map->size - tetrimino->width)
			map->m = map->m + (map->size - (map->m % map->size));
		if (check_fit(map, tetrimino))
		{
			insert_tetrimino(map, tetrimino);
			return (1);
		}
		map->m++;
	}
	return (0);
}
