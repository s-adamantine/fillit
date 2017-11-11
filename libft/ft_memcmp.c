/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 11:32:50 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/22 11:54:54 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*bs1;
	unsigned char	*bs2;

	bs1 = (unsigned char *)s1;
	bs2 = (unsigned char *)s2;
	while (n--)
	{
		if (*bs1 != *bs2)
		{
			return (*bs1 - *bs2);
		}
		bs1++;
		bs2++;
	}
	return (0);
}
