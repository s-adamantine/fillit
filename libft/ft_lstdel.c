/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 09:44:52 by sadamant          #+#    #+#             */
/*   Updated: 2017/09/27 12:49:28 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next_link;

	next_link = NULL;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		next_link = (*alst)->next;
		free(*alst);
		*alst = next_link;
	}
	*alst = NULL;
}
