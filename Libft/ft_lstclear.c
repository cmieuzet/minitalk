/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 09:14:59 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/18 15:24:47 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*keep;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	keep = *lst;
	while (tmp != NULL)
	{
		keep = keep->next;
		(del)(tmp->content);
		free(tmp);
		tmp = keep;
	}
	*lst = NULL;
}
