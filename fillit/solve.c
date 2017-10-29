/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 17:08:34 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/25 18:13:09 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//check if the tetrimino would fit at the map at m
//m iterates through map, t iterates through tetrimino
//at t = 4, m would offset to account for different map sizes
static int      check_fit(t_map *map, t_tet *tetrimino)
{
    int     m;
    int     t;

    t = 0;
    m = map->m;
    // printf("check fit in %d\n", map->m);
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

//copies out the tetrimino to the map at the m where check_fit succeds
static void insert_tetrimino(t_map *map, t_tet *tetrimino)
{
    int     t;
    int     m;

    t = 0;
    m = tetrimino->coord;
    while (tetrimino->str[t])
    {
        if (t != 0 && t % 4 == 0)
            m = m + (map->size) - 4;
        // printf("t[%c], ", tetrimino->str[t]);
        // printf("m[%d]: %c\n", m, map->str[m]);
        if (tetrimino->str[t++] == '#')
            (map->str)[m] = tetrimino->letter;
        m++;
    }
}

// iterates through map and calls check_fit at every m, if check_fit
// works, copies out tetrimino to the map, else increments m until
// it finds a fit.
static int  fit_tetrimino(t_map *map, t_tet *tetrimino)
{
    int     M;

    M = (int) ft_strlen(map->str) - (int) ft_strlen(tetrimino->str); //last m where it needs to try fitting
	while (map->m <= M)
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

t_map	*solve(t_tet **tetriminos, t_map *map)
{
    int i;

    i = 0;
    while (tetriminos[i]->str)
    {
        map->m = 0;
        fit_tetrimino(map, tetriminos[i]);
        printf("tetriminos->str[%d]: %s\n", i, tetriminos[i]->str);
        printf("map->str: %s\n", map->str);
        i++;
    }
    return (map);
}

//need this so that bc you can't instantiate when you backtrack
t_map    *solve_entry(t_tet **tetriminos)
{
    t_map   *map;

    map = init_map(tetriminos);
    solve(tetriminos, map);
    print_map(map);
    return (map);
}
