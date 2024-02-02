/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:06:05 by ioztimur          #+#    #+#             */
/*   Updated: 2022/12/14 20:06:06 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*arr;

	if (!s1)
	{
		return (NULL);
	}
	if (!set)
	{
		ft_strdup(s1);
	}
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
		end--;
	arr = (char *)malloc(sizeof(char) * end - start + 1);
	if (arr)
	{
		ft_strlcpy(arr, &s1[start], end - start + 1);
	}
	return (arr);
}
