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

//check if the tetrimino would fit at the map at m
//m iterates through map, t iterates through tetrimino
//at t = 4, m would offset to account for different map sizes
static int      check_fit(t_map *map, t_tet *tetrimino)
{
    int     m;
    int     t;

    t = 0;
    m = map->m;
    printf("check fit in %d\n", map->m);
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
        printf("t[%c], ", tetrimino->str[t]);
        printf("m[%d]: %c\n", m, map->str[m]);
        if (tetrimino->str[t++] == '#')
            (map->str)[m] = tetrimino->letter;
        m++;
    }
}

//goes through the map from the beginning and tries to find an empty '.'
//at a location that would accomodate for the width of the tetrimino.
//must be able to call this in a loop for each tetrimino and find the m
//locations
void    scout_spot(t_map *map, t_tet *tetrimino)
{
    int x;
    int m;

    m = map->m;
    while (map->str[m])
    {
        x = m % map->size; //the x coordinate
        if (x > map->size - tetrimino->width)
            m = m + (map->size - x); //this doesn't work if the tet goes to the left....
        if (map->str[m] == '.')
        {
            map->m = m;
            return;
        }
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
        scout_spot(map, tetrimino);
        if (check_fit(map, tetrimino))
        {
            insert_tetrimino(map, tetrimino);
            return (1);
        }
        map->m++; //fix this atrocity though
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
        printf("tetriminos->width[%d]: %d\n", i, tetriminos[i]->width);
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
