/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 11:43:02 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/02 15:10:32 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		ch;
	unsigned char		*dest;
	const unsigned char	*source;

	ch = c;
	dest = dst;
	source = src;
	while (n--)
	{
		*dest = *source;
		if (*source == ch)
		{
			return (dest + 1);
		}
		source++;
		dest++;
	}
	return (NULL);
}
