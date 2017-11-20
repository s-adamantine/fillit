/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 23:37:16 by sadamant          #+#    #+#             */
/*   Updated: 2017/11/20 14:02:03 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** reduce tetrimino starting from the first index to the last
** instance of #.
*/

static t_tet	*get_next_tetrimino(char c, char *str)
{
	t_tet	*t;

	t = (t_tet *)malloc(sizeof(t_tet));
	t->letter = c;
	if (str)
	{
		t->str = reduce_tetrimino(str);
		t->width = tet_width(str);
		t->height = ft_strlen(t->str) / 4 + 1;
		t->coord = -1;
	}
	else
		t->str = NULL;
	ft_strdel(&str);
	return (t);
}

/*
** an array of valid tetrimino structs
*/

t_tet			**insert_array(char *buf)
{
	int		i;
	char	letter;
	char	*tet;
	t_tet	**tetriminos;

	i = 0;
	letter = 'A';
	if (!(tetriminos = ft_memalloc(sizeof(t_tet *) * 27)))
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
	while (i < 27)
		tetriminos[i++] = get_next_tetrimino('\0', NULL);
	return (tetriminos);
}
