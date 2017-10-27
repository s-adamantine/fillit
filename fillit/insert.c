/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:37:16 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/26 23:37:25 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	count_hash(char *t)
{
	int count;

	count = 0;
	while (*t)
	{
		if (*t++ == '#')
			count++;
	}
	if (count != 4)
		return (0);
	return (1);
}

static int	connections(char *t)
{
	int	i;
	int	connect;

	i = 0;
	connect = 0;
	while (t[i])
	{
		if (t[i] == '#')
		{
			if ((i + 1 < 20) && t[i + 1] == '#')
				connect++;
			if ((i - 1 >= 0) && t[i - 1] == '#')
				connect++;
			if ((i + 5 < 20) && t[i + 5] == '#')
				connect++;
			if ((i - 5 >= 0) && t[i - 5] == '#')
				connect++;
		}
		i++;
	}
	return (connect == 6 || connect == 8);
}

//input: unreduced tetrimino string
//checks the coordinate of the # to see if it's a min or a max
//output: width of the tetrimino
static int	tet_width(char *t)
{
	int	x;
	int l; //leftmost
	int r; //rightmost

	x = 0;
	l = 4;
	r = 0;
	while(*t)
	{
		if (x % 5 == 0) //the x coordinate will always be < 4
			x = 0;
		if (*t++ == '#')
		{
			if (x < l)
				l = x;
			if (x > r)
				r = x;
		}
		x++;
	}
	return (r - l + 1);
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

static t_tet	*get_next_tetrimino(char c, char *str)
{
	t_tet	*t;

	t = (t_tet *)malloc(sizeof(t_tet));
	t->letter = c;
	if (str)
	{
		t->str = reduce_tetrimino(str);
		t->width = tet_width(str);
	}
	else
		t->str = NULL;
	ft_strdel(&str);
	return (t);
}

// an array of valid tetrimino structs
t_tet			**insert_array(char *buf)
{
	int		i;
	char	letter;
	char	*tet;
	t_tet	**tetriminos;

	i = 0;
	letter = 'A';
	if (!(tetriminos = ft_memalloc(sizeof(t_tet *) * 26)))
		return (NULL);
	while (*buf)
	{
		tet = ft_strnew(20);
		tet = ft_strncpy(tet, buf, 20);
		if (count_hash(tet) && connections(tet))
			tetriminos[i++] = get_next_tetrimino(letter++, tet);
		else
			return (NULL);
		buf = buf + 21;
	}
	while (i < 26)
		tetriminos[i++] = get_next_tetrimino('\0', NULL);
	return (tetriminos);
}
