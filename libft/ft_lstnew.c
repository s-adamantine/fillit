/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 22:53:55 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/24 20:49:29 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content == NULL)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else
		{
			new->content = malloc(content_size);
			if (new->content)
			{
				ft_memcpy(new->content, content, content_size);
			}
			new->content_size = (size_t)malloc(sizeof(size_t));
			new->content_size = content_size;
		}
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
