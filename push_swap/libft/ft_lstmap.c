/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:33:06 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 11:46:01 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_del_return(t_list *lst, void (*del)(void *))
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		del(lst->content);
		free(lst);
		lst = next;
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
	void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_prev;
	t_list	*new_curr;

	new_head = ft_lstnew(f(lst->content));
	if (!new_head)
		return (0);
	new_prev = new_head;
	lst = lst->next;
	while (lst)
	{
		new_curr = ft_lstnew(f(lst->content));
		if (!new_curr)
			return (ft_del_return(new_head, del));
		new_prev->next = new_curr;
		new_prev = new_curr;
		lst = lst->next;
	}
	return (new_head);
}
