/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:18:31 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/25 18:15:19 by sadamant         ###   ########.fr       */
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

static int	isvalid_tetrimino(char	*tetrimino)
{
	char	**hardcoded;

	if(!count_hash(tetrimino))
		return (0);
	hardcoded = valid_tetriminos();
	while (*hardcoded)
	{
		if (ft_strcmp(reduce_tetrimino(tetrimino), *hardcoded++) == 0)
			return (1);
	}
	return (0);
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

// an array of valid tetriminos
t_tet			**insert_array(char *buf)
{
	int		i;
	char	letter;
	char	*str;
	t_tet	**tetriminos;

	i = 0;
	letter = 'A';
	if (!(tetriminos = ft_memalloc(sizeof(t_tet *) * 26)))
		return (NULL);
	while (*buf)
	{
		str = ft_strnew(20);
		str = ft_strncpy(str, buf, 20);
		if (isvalid_tetrimino(str))
			tetriminos[i++] = get_next_tetrimino(letter++, str);
		else
			return (NULL);
		buf = buf + 21;
	}
	while (i < 26)
		tetriminos[i++] = get_next_tetrimino('\0', NULL);
	return (tetriminos);
}
