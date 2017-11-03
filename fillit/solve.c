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
        if (tetrimino->str[t++] == '#')
            (map->str)[m] = tetrimino->letter;
        m++;
    }
}

// clear previous tet
static void clear_tetrimino(t_map *map, t_tet *tetrimino)
{
    int t;
    int m;

    t = 0;
    m = tetrimino->coord;
    while (tetrimino->str[t])
    {
        if (tetrimino->str[t] == '#')
            (map->str)[m] = '.';
        m++;
        t++;
    }
}

// iterates through map and calls check_fit at every m, if check_fit
// works, copies out tetrimino to the map, else increments m until
// it finds a fit.
static int  fit_tetrimino(t_map *map, t_tet *tetrimino)
{
    int     M;

    M = (int) ft_strlen(map->str) - (int) ft_strlen(tetrimino->str); //last m where it needs to try fitting
    map->m = tetrimino->coord + 1; //set initial t->coord to -1, and so if there's already a slot, it increments it by one (for the recursion!)
	while (map->m <= M)
	{
        if (map->m % map->size > map->size - tetrimino->width)
            map->m = map->m + (map->size - (map->m % map->size));
        if (check_fit(map, tetrimino))
        {
            insert_tetrimino(map, tetrimino);
            print_map(map);
            printf("\n");
            return (1);
        }
        map->m++;
	}
    printf("this tet doesn't fit at %d.\n", tetrimino->coord);
	return (0);
}

//clears the previous tetrimino and refits that current tetrimino somewhere else.
static int refit_tetrimino(t_map *map, t_tet *tetrimino)
{
    // if (!check_fit(map, tetrimino))
    //     return (0);
    if (tetrimino->coord + ft_strlen(tetrimino->str) == ft_strlen(map->str))
        return (0); //don't want to clear if you can't move c to the right anymore.
    clear_tetrimino(map, tetrimino);
    return (fit_tetrimino(map, tetrimino));
}

//keeps the immediately previous tetrimino and refits the one before it somewhere else.
t_map	*solve(t_tet **tetriminos, t_map *map, int i)
{
    printf("now trying to solve: %s\n", tetriminos[i]->str);
    if (tetriminos[i]->str == NULL)
        return (0);
    if (!fit_tetrimino(map, tetriminos[i]))
    {
        if (!refit_tetrimino(map, tetriminos[--i])) //if you can't refit the previous tet anymore
        {
            refit_tetrimino(map, tetriminos[--i]); //refit the one before that
            i += 2; //not sure why this one works here.
            return (solve(tetriminos, map, i)); //try and solve the current one again
        }
        else
            return (solve(tetriminos, map, ++i));
    }
    return (solve(tetriminos, map, ++i));
}

//need this so that bc you can't instantiate when you backtrack
t_map    *solve_entry(t_tet **tetriminos)
{
    int     i;
    t_map   *map;

    i = 0;
    map = init_map(tetriminos);
    solve(tetriminos, map, i);
    print_map(map);
    return (map);
}
