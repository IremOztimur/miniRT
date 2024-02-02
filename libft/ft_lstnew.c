/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 02:01:10 by ioztimur          #+#    #+#             */
/*   Updated: 2022/12/14 20:43:36 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;
	t_list	*temp;

	lst = NULL;
	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
	{
		return (NULL);
	}
	temp->content = (void *)content;
	temp->next = NULL;
	lst = temp;
	return (lst);
}
