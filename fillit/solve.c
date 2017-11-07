/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:08:34 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/07 12:23:53 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** i = current tet, j = current backtrack movement.
** if you can fit the current tet in, you recurse and fit the next tet in.
** if you can't fit the current tet in, instantiate backtracking.
*/

void	reset_coordinates(t_tet **tetriminos, int j, int i)
{
	while (j != i)
		tetriminos[++j]->coord = -1;
}

int		solve(t_tet **tetriminos, t_map *map, int i)
{
	int j;

	if (tetriminos[i]->str == NULL)
		return (1);
	if (ft_strlen(tetriminos[i]->str) > ft_strlen(map->str))
		return (0);
	while (!fit_tetrimino(map, tetriminos[i]))
	{
		j = i - 1;
		while (!refit_tetrimino(map, tetriminos[j]))
		{
			if (--j < 0)
				return (0);
		}
		reset_coordinates(tetriminos, j, i);
		return (solve(tetriminos, map, ++j));
	}
	return (solve(tetriminos, map, ++i));
}

t_map	*solve_entry(t_tet **tetriminos)
{
	int		i;
	t_map	*map;

	i = 0;
	map = init_map(tetriminos);
	while (!solve(tetriminos, map, i))
	{
		map = expand_map(map);
		reset_coordinates(tetriminos, -1, 25);
	}
	print_map(map);
	return (map);
}
