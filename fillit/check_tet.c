/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardcoded_tetrimino.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 17:46:07 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/17 19:55:50 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char	**ft_darraynew(int i, int j)
{
	int		n;
	char	**darray;

	n = 0;
	darray = ft_memalloc(i);
	while (n < i)
		darray[n++] = ft_memalloc(j);
	return (darray);
}

char	**valid_tetriminos(void)
{
    char    **valids;

    valids = ft_darraynew(19, 14);
    valids[1] = "####";
    valids[2] = "##..##";
    valids[3] = "#...#...#...#";
    valids[4] = "##..#...#";
    valids[5] = "#...##..#";
    valids[6] = "#...#...##";
    valids[7] = "#...#..##";
    valids[8] = "##...#...#";
    valids[9] = "#...###";
    valids[10] = "#.###";
    valids[11] = "###.#";
    valids[12] = "###...#";
    valids[13] = "##.##";
    valids[14] = "#..##..#";
    valids[15] = "###..#";
    valids[16] = "#..##...#";
    valids[17] = "###..#";
    valids[18] = "#..###";
    valids[19] = "##...##";
    return (valids);
}

char	*reduce_tetrimino(char *t)
{
    int     count;
    char    *reduced;
    char    *reducedcpy;

    count = 0;
    t = strchr(t, '#');
    reduced = (char *)malloc(sizeof(char) * 14);
    reducedcpy = reduced;
    while (*t && count < 4)
    {
        if (*t == '\n')
            t++;
        if (*t == '#')
            count++;
        *reduced++ = *t++;
    }
    *reduced = '\0';
    return (reducedcpy);
}
