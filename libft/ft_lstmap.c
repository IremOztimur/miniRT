/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:55:57 by ioztimur          #+#    #+#             */
/*   Updated: 2022/12/24 22:45:15 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*arr;
	t_list	*new;

	if (!lst || !(*f) || !del)
	{
		return (0);
	}
	arr = 0;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!(new))
		{
			ft_lstclear(&arr, del);
			return (arr);
		}
		ft_lstadd_back(&arr, new);
		lst = lst->next;
	}
	return (arr);
}
