/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 18:38:27 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/09 18:47:57 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (dest[i])
	{
		i++;
	}
	while (n-- > 0 && *src)
	{
		dest[i++] = *src++;
	}
	dest[i] = '\0';
	return (dest);
}
