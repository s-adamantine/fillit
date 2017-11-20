/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 12:16:09 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/21 15:29:37 by sadamant         ###   ########.fr       */
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
		if (map->size < 4 && t % 4 >= map->size)
			t = t + (4 - map->size);
		if (map->size > 4 && t != 0 && t % 4 == 0)
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
** iterates through map starting from the last place that the tet had fit in
** and fits in the tetrimino at the next m coordinate that it fits in.
*/

int				fit_tetrimino(t_map *map, t_tet *tetrimino)
{
	int last_m;

	if (map->size > 3)
		last_m = (int)ft_strlen(map->str) - (int)ft_strlen(tetrimino->str);
	else
		last_m = (int)((ft_strlen(map->str)) - \
			((tetrimino->height - 1) * map->size) - tetrimino->width);
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
