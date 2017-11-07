/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tetrimino_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgaia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 19:14:14 by rgaia             #+#    #+#             */
/*   Updated: 2017/11/07 11:49:45 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_valid_format(char *buf)
{
	int		i;
	int		row_len;
	int		column_len;

	i = -1;
	row_len = 0;
	column_len = 0;
	while (buf[++i])
	{
		if (row_len < 4 && VALID_CHAR(buf[i]))
			row_len++;
		else if (row_len == 4 && buf[i] == '\n')
		{
			row_len = 0;
			column_len++;
			if (column_len == 4 && buf[i + 1] == '\n')
			{
				column_len = 0;
				i++;
			}
		}
		else
			return (0);
	}
	return (column_len == 4 && buf[i - 1] != buf[i - 2]);
}

int			parse_tetrimino_file(int fd, char *buf)
{
	int		buf_size;

	buf_size = read(fd, buf, BUF_SIZE);
	close(fd);
	if (buf_size > 545 || buf_size < 20)
		return (0);
	buf[buf_size] = '\0';
	return (check_valid_format(buf));
}
