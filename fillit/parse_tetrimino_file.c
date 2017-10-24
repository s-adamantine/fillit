/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrimino_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:14:14 by rgaia             #+#    #+#             */
/*   Updated: 2017/10/12 17:26:54 by rgaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** These function reads a file into a buffer, and checks for invalid file format and characters
** @in: open file descriptor to read from file to buf
** @out: number of tetriminos in file that have been saved in buf
** @error: returns -1 if any of following happens:
**			1. contains any character other than '.' and '#'
**			2. number of characters per line is different than 4 + 1 (new line)
**			3. piece (doesn't check for valid tetrimino) contains less or more than 4 lines
**			4. invalid tetrimino piece is checked within insert_array
*/

/*
** Checks for conditions 1, 2, and 3 of parse_tetrimino_file
*/
static int	check_valid_format(char *buf)
{
	int		i;
	int		row_len;
	int		colum_len;

	i = 0;
	row_len = 0;
	colum_len = 0;
	while (buf[i])
	{
		if (row_len < 4 && VALID_CHAR(buf[i]))
			row_len++;
		else if (row_len == 4 && buf[i] == '\n')
		{
			row_len = 0;
			colum_len++;
			if (colum_len == 4 && buf[i + 1] == '\n') //increments passed new line splitting tetriminos
			{
				colum_len = 0;
				i++;
			}
		}
		else
			return (0);
		i++;
	}
	return (colum_len == 4 && buf[i - 1] != buf[i - 2]); //checks there isn't a new line at end of file
}

int			parse_tetrimino_file(int fd, char *buf)
{
	int		buf_size;

	buf_size = read(fd, buf, BUF_SIZE);
	close(fd);
	if (buf_size > 545 || buf_size < 20) //checks contains min 1, max 26 tetriminos
		return (0);
	buf[buf_size] = '\0';
	return (check_valid_format(buf));
}
