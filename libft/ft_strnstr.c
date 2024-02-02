/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:32:58 by ioztimur          #+#    #+#             */
/*   Updated: 2022/12/21 16:31:29 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*ptr;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	ptr = (char *)haystack;
	i = 0;
	if (!needle_len)
		return (ptr);
	else if (!(*needle) || len == 0)
		return (0);
	while (ptr[i] && i < len)
	{
		j = 0;
		while (ptr[i + j] && needle[j] && ptr[i + j] == needle[j] && i
			+ j < len)
		{
			j++;
		}
		if (needle_len == j)
			return (ptr + i);
		i++;
	}
	return (0);
}
