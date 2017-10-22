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

t_map	*init_map(t_tetri **tetriminos)
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
    printf("ntet is %d\n", ntet);
    printf("size is %d\n", size);
	return (map);
}

//check if the tetrimino would fit at the map at m
//at i = 4, iterate skip i + (size - 4).

//check for t so that it checks the fit properly w/ offset
static int      check_fit(t_map *map, t_tetri *tetrimino)
{
    int     m;
    int     t;
    char    *tet_str;
    char    *map_str;

    m = map->m;
    t = 0;
    tet_str = tetrimino->str;
    map_str = map->str;
    printf("checking at m: %d\n", map->m);
    while (tet_str[t])
    {
        if (t % 4 == 0)
        {
            m = m + (map->size) - 4;
        }
        if (tet_str[t++] == '#')
        {
            if (map_str[m] == '.')
            {
                m++;
            }
            else
                return (0);
        }
        else
            m++;
    }
    return (1);
}

// copies out the tetrimino to the map starting at m (when check_fit suceeds)
// at this point map->m should be where you're supposed to fit it.


//instatntiate t so that it inserts properly w/ offset
static void insert_tetrimino(t_map *map, t_tetri *tetrimino)
{
    int     m;
    char    *tet_str;

    m = map->m;
    tet_str = tetrimino->str;
    while (*tet_str)
    {
        if (*tet_str++ == '#')
            (map->str)[m++] = tetrimino->letter;
        else
            m++;
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
	while (map->m <= M)
	{
        if (check_fit(map, tetrimino))
        {
            insert_tetrimino(map, tetrimino);
            map->m++; //since it fits, the next m would start here
            return (map);
        }
        else
        {
            map->m++;
        }
	}
	return (map);
}

t_map	*solve(t_tetri **tetriminos, t_map *map)
{
    int i;

    i = 0;
    while (tetriminos[i]->str)
    {
        fit_tetrimino(map, tetriminos[i]);
        printf("tetriminos->str[%d]: %s\n", i, tetriminos[i]->str);
        printf("map->str: %s\n", map->str);
        i++;
    }
    return (map);
}

//need this so that bc you can't instantiate when you backtrack
t_map    *solve_entry(t_tetri **tetriminos)
{
    t_map   *map;

    map = init_map(tetriminos);
    solve(tetriminos, map);
    print_map(map);
    return (map);
}
