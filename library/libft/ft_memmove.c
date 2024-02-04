/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:14:12 by ioztimur          #+#    #+#             */
/*   Updated: 2022/12/24 19:58:41 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr_dst;
	const char	*ptr_src;

	ptr_dst = (char *)dst;
	ptr_src = (char *)src;
	if (!ptr_dst && !ptr_src)
	{
		return (NULL);
	}
	i = 0;
	if (ptr_src < ptr_dst)
	{
		while (++i <= len)
			ptr_dst[len - i] = ptr_src[len - i];
	}
	else
	{
		while (len > 0)
		{
			*(ptr_dst++) = *(ptr_src++);
			len--;
		}
	}
	return (dst);
}
