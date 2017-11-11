/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 18:35:59 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/09 06:24:37 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*destcpy;

	destcpy = dest;
	while (n-- > 0)
	{
		if (*src)
			*(char *)dest++ = *(char *)src++;
		else
			*(char *)dest++ = '\0';
	}
	return (destcpy);
}
