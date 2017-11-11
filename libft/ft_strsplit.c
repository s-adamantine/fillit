/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 10:11:30 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/04 12:23:11 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 1;
	if (s[i] == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
			{
				i++;
			}
			count++;
		}
		else
		{
			i++;
		}
	}
	return (count);
}

static int	get_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s++ != c)
		len++;
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		len;
	char	**split;

	i = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
		if (*s != c)
		{
			j = 0;
			len = get_wordlen(s, c);
			split[i] = (char *)malloc(sizeof(char) * (len + 1));
			while (len--)
				split[i][j++] = *s++;
			split[i++][j] = '\0';
		}
		else
			s++;
	split[i] = NULL;
	return (split);
}
