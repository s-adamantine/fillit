/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:14:07 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/29 20:31:17 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s1, int c1, size_t n)
{
	unsigned char	*s;
	unsigned char	c;

	s = (unsigned char *)s1;
	c = (unsigned char)c1;
	while (n--)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}
	return (NULL);
}
