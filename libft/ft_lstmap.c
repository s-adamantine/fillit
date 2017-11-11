/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadamant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 21:06:01 by sadamant          #+#    #+#             */
/*   Updated: 2017/10/04 00:21:40 by sadamant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*current;
	t_list	*temp;

	temp = f(lst);
	current = ft_lstnew(temp->content, temp->content_size);
	head = current;
	lst = lst->next;
	while (lst)
	{
		temp = f(lst);
		current->next = ft_lstnew(temp->content, temp->content_size);
		current = current->next;
		lst = lst->next;
	}
	return (head);
}
