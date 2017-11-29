/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:40:17 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/07 11:37:57 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (map->str[i])
	{
		if (i != 0 && i % (map->size) == 0)
		{
			ft_putchar('\n');
			ft_putchar(map->str[i++]);
		}
		else
			ft_putchar(map->str[i++]);
	}
	ft_putchar('\n');
}

t_map	*create_map(int size)
{
	int		i;
	t_map	*map;
	char	*map_str;

	i = 0;
	map = ft_memalloc(sizeof(t_map));
	map_str = ft_memalloc(size * size);
	while (i < size * size)
		map_str[i++] = '.';
	map->size = size;
	map->str = map_str;
	return (map);
}

t_map	*init_map(t_tet **tetriminos)
{
	int		ntet;
	int		size;

	ntet = 0;
	size = 2;
	while ((*tetriminos++)->str)
		ntet++;
	while ((size * size) < ntet * 4)
		size++;
	return (create_map(size));
}

t_map	*expand_map(t_map *old_map)
{
	int		size;

	size = old_map->size + 1;
	free(old_map);
	return (create_map(size));
}
