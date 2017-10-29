/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 13:17:42 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/17 19:49:13 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	@in: single file containing up to 26 tetriminos, separated by empty line. No empty line after last tetrimino.
**  @out: stdout smallest square solution with new line. No empty line
**  @errors:
**          1. invalid use of fillit command
**				- displays 'usage' message
**			2. invalid file format
**				- displays 'error' to stdout and exits
*/

static void		exit_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

int				main(int argc, char **argv)
{
	int			fd;
	t_tet		**tetriminos;
	char		*buf;

	buf = ft_memalloc(BUF_SIZE);
	if (argc != 2)
		exit_error("usage: ./fillit source_file");
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	if (!(parse_tetrimino_file(fd, buf)))
		exit_error("error");
	if (!(tetriminos = insert_array(buf)))
		exit_error("error in insert.");
	solve_entry(tetriminos);
	// ft_memdel((void**)&tetriminos);
	// ft_memdel((void**)&buf);
	return (0);
}
