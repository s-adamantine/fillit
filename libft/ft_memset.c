/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 20:03:18 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/23 20:22:10 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	c1;
	unsigned char	*b1;

	b1 = (unsigned char *)b;
	c1 = (unsigned char)c;
	while (len--)
	{
		*b1++ = c1;
	}
	return (b);
}
