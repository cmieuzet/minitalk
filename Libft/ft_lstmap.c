/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:16:09 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/18 15:08:08 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmpnew;

	if (!lst || !f)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	tmpnew = new;
	while (lst->next)
	{
		lst = lst->next;
		ft_lstadd_back(&tmpnew, ft_lstnew(f(lst->content)));
		if (!new)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		tmpnew = tmpnew->next;
	}
	return (new);
}
