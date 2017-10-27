/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:40:17 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/26 23:40:24 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// iterate through map and prints a . or the character
// (depending on the tetrimino that it's in)
void    print_map(t_map *map)
{
    size_t      i;

    i = 0;
    while (map->str[i])
    {
        if (i % (map->size) == 0)
        {
            ft_putchar('\n');
            ft_putchar(map->str[i++]);
        }
        else
            ft_putchar(map->str[i++]);
    }
}

t_map	*init_map(t_tet **tetriminos)
{
    int		i;
    int 	ntet;
	int    	size;
	char	*map_str;
    t_map   *map;

    i = 0;
    ntet = 0;
	size = 2;
    while ((*tetriminos++)->str)
		ntet++;
	while ((size * size) < ntet * 4)
        size++;
	map = ft_memalloc(sizeof(t_map));
	map_str = ft_memalloc(size * size); //not allocating for end /0
	while (i < size * size)
		map_str[i++] = '.';
    map->size = size;
	map->str = map_str;
	return (map);
}
