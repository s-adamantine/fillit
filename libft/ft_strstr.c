/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 13:28:25 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/21 16:31:26 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_substring(const char *haystack, const char *needle)
{
	while (*needle)
	{
		if (*haystack++ == *needle++)
			;
		else
			return (-1);
	}
	return (1);
}

char		*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strcmp(needle, "") == 0)
	{
		return ((char *)haystack);
	}
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			if (check_substring(haystack, needle) > 0)
			{
				return ((char *)haystack);
			}
		}
		haystack++;
	}
	return (NULL);
}
