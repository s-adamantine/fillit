/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:08:34 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/19 17:08:45 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



static t_map	*init_map(t_tetri  **tetriminos)
{
	int			i;
	int			j;
	int			size;
	t_map		*map;

	i = 0;
	j = 0;
    size = init_size(tetriminos);
	// if (size * size < ft_strlen(tetriminos))
	map = (t_map*)malloc(sizeof(t_map));
    printf("initial size of map");
	map->size = size;
	while (i < 15)
	{
		while (j < 15)
		{
			if (j < size && i < size)
				(map->map)[i][j] = '.';
			else
				(map->map)[i][j] = '\0';
			j++;
		}
		j = 0;
		i++;
	}
	return (map);
}

static void		print_map(t_map *map)
{
	size_t		i;

	i = 0;
	while (i < (map->size) && (map->map)[i])
		ft_putendl((map->map)[i++]);
}
