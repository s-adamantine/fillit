/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 20:50:10 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/30 15:53:59 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	ret;

	if (size > ft_strlen(dest))
	{
		ret = ft_strlen(src) + ft_strlen(dest);
		size = size - ft_strlen(dest) - 1;
		dest = dest + ft_strlen(dest);
		while (*src && size--)
		{
			*dest++ = *src++;
		}
		*dest = '\0';
		return (ret);
	}
	else
	{
		return (size + ft_strlen(src));
	}
}
