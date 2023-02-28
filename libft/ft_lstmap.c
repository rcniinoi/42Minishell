/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:25:28 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/18 00:40:28 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_copylist(t_list *head)
{
	t_list	*new;

	if (head == NULL)
		return (NULL);
	else
	{
		new = ft_lstnew(head->content);
		new->next = ft_copylist(head->next);
		return (new);
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*temp;
	t_list	*templst;

	newl = ft_copylist(lst);
	templst = newl;
	while (templst != NULL)
	{
		templst->content = f(templst->content);
		templst = templst->next;
	}
	if (newl == NULL)
	{
		temp = NULL;
		while (newl != NULL)
		{
			temp = newl->next;
			del(newl->content);
			free(newl);
			newl = temp;
		}
	}
	return (newl);
}
