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

void    print_map(t_map *map)
{
    size_t      i;
    char        *map_str;

    i = 0;
    map_str = map->str;
    while (map_str[i])
    {
        if (i % (map->size + 1) == 0)
            ft_putchar('\n');
        else
            ft_putchar(map_str[i++]);
    }
}


static void		exit_error(char *str)
{
	ft_putendl(str);
	exit(EXIT_FAILURE);
}

/*
** TODO: recursive backtracking solver
** TODO: init buf within parse_tetrimino_file and return it (not mandatory to do, but better practice? idk)
**			- If not, then remember to free buf in case any error occurs. Quick solution is to pass buf
				to error_exit, but makes no sense to free memory within an error handler. Works, not nice?
*/

int				main(int argc, char **argv)
{
	int			fd;
	t_tetri		**tetriminos;
	// t_map		*map;
	char		*buf;

	buf = ft_memalloc(BUF_SIZE);
	if (argc != 2)
		exit_error("usage: ./fillit source_file");
	if (!(fd = open(argv[1], O_RDONLY)))
		exit(EXIT_FAILURE);
	if (!(parse_tetrimino_file(fd, buf)))
		exit_error("error here");
	if (!(tetriminos = insert_array(buf))) //change initial implentation to insert from buffer rather than file
		exit_error("error");
	solve_entry(tetriminos);
	// solve_smallest_square(tetriminos, map);
	// print_map(map);
	// ft_memdel((void**)&tetriminos);
	// ft_memdel((void**)&buf);
	return (0);
}
