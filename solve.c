/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:08:34 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/14 10:44:17 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** i = current tet, j = current backtrack movement.
** if you can fit the current tet in, you recurse and fit the next tet in.
** if you can't fit the current tet in, instantiate backtracking.
*/

static void	reset_coordinates(t_tet **tetriminos, int j, int i)
{
	while (j < i)
		tetriminos[j++]->coord = -1;
}

int			solve_map(t_tet **tetriminos, t_map *map, int i)
{
	int j;

	if (tetriminos[i]->height > map->size || tetriminos[i]->width > map->size)
		return (0);
	while (tetriminos[i]->str != NULL)
	{
		while (!fit_tetrimino(map, tetriminos[i]))
		{
			j = i - 1;
			clear_tetrimino(map, tetriminos[j]);
			while (!fit_tetrimino(map, tetriminos[j]))
			{
				if (--j < 0)
					return (0);
				clear_tetrimino(map, tetriminos[j]);
			}
			reset_coordinates(tetriminos, j + 1, i);
			i = j + 1;
		}
		i++;
	}
	return (1);
}

t_map		*solve(t_tet **tetriminos)
{
	int		i;
	t_map	*map;

	i = 0;
	map = init_map(tetriminos);
	while (!solve_map(tetriminos, map, i))
	{
		map = expand_map(map);
		reset_coordinates(tetriminos, 0, 26);
	}
	print_map(map);
	return (map);
}
