/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 16:45:10 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/04 12:03:26 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	check_end(char const *s)
{
	while (*s)
	{
		if (*s == ' ' || *s == '\n' || *s == '\t')
			s++;
		else
			return (-1);
	}
	return (1);
}

static char	*make_trim(char const *str, int len)
{
	char *trimmed;

	trimmed = (char *)malloc(sizeof(char) * (len + 1));
	if (trimmed)
	{
		trimmed = ft_strncpy(trimmed, str, len);
		trimmed[len] = '\0';
		return (trimmed);
	}
	return (NULL);
}

char		*ft_strtrim(char const *s)
{
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	len = 0;
	while (*s == ' ' || *s == '\n' || *s == '\t')
	{
		s++;
	}
	str = (char *)s;
	while (str[len])
	{
		if (str[len] == ' ' || str[len] == '\n' || str[len] == '\t')
		{
			if (check_end(str + len) > 0)
				return (make_trim(str, len));
		}
		len++;
	}
	return (make_trim(str, len));
}
