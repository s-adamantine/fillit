/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 12:05:13 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/29 20:31:31 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	*temp;

	temp = (unsigned char *)malloc(sizeof(unsigned char) * len);
	ft_memcpy(temp, src, len);
	ft_memcpy(dest, temp, len);
	free(temp);
	return (dest);
}
