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

static t_map	*init_map(t_tetri **tetriminos)
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

//check if the tetrimino would fit at the map at m
static int      check_fit(t_map *map, t_tetri *tetrimino)
{
    int     m;
    char    *tet_str;
    char    *map_str;

    m = map->m;
    tet_str = tetrimino->str;
    map_str = map->str;
    while (*tet_str)
    {
        if (*tet_str++ == '#')
        {
            if (map_str[m] == '.')
                m++;
            else
                return (0);
        }
        else
            m++;
    }
    return (1);
}

// copies out the tetrimino to the map at the position (when check_fit suceeds)
// at this point map->m should be where you're supposed to fit it.
static void insert_tetrimino(t_map *map, t_tetri *tetrimino)
{
    int     m;
    char    *tet_str;

    m = map->m;
    tet_str = tetrimino->str;
    while (*tet_str)
    {
        (map->str)[m++] = *tet_str++;
    }
}

// iterates through map and calls check_fit at every m, if check_fit
// works, copies out tetrimino to the map, else increments m until
// it finds a fit.
static t_map 	*fit_tetrimino(t_map *map, t_tetri *tetrimino)
{
    int     M;
	char	*cur_str;

	cur_str = tetrimino->str;
    M = (int) ft_strlen(map->str) - (int) ft_strlen(tetrimino->str);
	while (map->m < M)
	{
        printf("cur str: %s\n", cur_str);
        printf("%d\n", check_fit(map, tetrimino));
        if (check_fit(map, tetrimino))
        {
            insert_tetrimino(map, tetrimino);
            return (map);
        }
        else
            map->m++;
	}
	return (map);
}

t_map	*solve(t_tetri **tetriminos, t_map *map)
{
    printf("fitting the first tetrimino.\n");
    fit_tetrimino(map, tetriminos[0]);
    printf("fitting the second tetrimino.\n");
    fit_tetrimino(map, tetriminos[1]);
    printf("the final map is: %s\n", map->str);
    // map = fit_tetrimino(map, tetriminos[2]);
    return (map);
}

t_map    *solve_entry(t_tetri **tetriminos)
{
    t_map   *map;

    map = init_map(tetriminos);
    solve(tetriminos, map);
    return (map);
}
