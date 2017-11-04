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

//clears a tetrimino and tries to refit that tetrimino further along the
//map. if you can't fit that tet any further to the right, it reinserts it
//at the same spot and returns 0.
static int refit_tetrimino(t_map *map, t_tet *tetrimino)
{
    clear_tetrimino(map, tetrimino);
    if (!fit_tetrimino(map, tetrimino))
    {
        insert_tetrimino(map, tetrimino);
        return (0);
    }
    return (1);
}

t_map	*solve(t_tet **tetriminos, t_map *map, int i)
{
    printf("now trying to solve: %s\n", tetriminos[i]->str);
    if (tetriminos[i]->str == NULL)
        return (0);
    while (!fit_tetrimino(map, tetriminos[i])) //try to fit the current tet in, if you can't-
    {
        if (!refit_tetrimino(map, tetriminos[--i])) //refits the previous one and tries to fit current tet in.
        {
            if (!refit_tetrimino(map, tetriminos[--i])) //if that doesn't work, tries to refit the tet before that
                return (0);
            i += 2; //not sure why this one works here.
            return (solve(tetriminos, map, i)); //try and solve the current one again
        }
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
