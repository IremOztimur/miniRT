/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:32:13 by ioztimur          #+#    #+#             */
/*   Updated: 2023/04/26 22:23:33 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_len;
	size_t	s2_len;
	char	*arr;

	if (!s1 || !s2)
		return (ft_strdup(""));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * ((s1_len + s2_len) + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (s1[++i])
		arr[i] = s1[i];
	i = 0;
	while (s2[i])
	{
		arr[s1_len] = s2[i];
		s1_len++;
		i++;
	}
	arr[s1_len] = 0;
	return (arr);
}
