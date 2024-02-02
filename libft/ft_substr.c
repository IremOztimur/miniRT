/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 21:22:28 by ioztimur          #+#    #+#             */
/*   Updated: 2022/10/22 22:14:27 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*p;

	if (!s)
		return (0);
	j = 0;
	if (ft_strlen(s) < start)
	{
		return (ft_strdup(""));
	}
	if (len > (ft_strlen(s) - (size_t)start))
		len = (ft_strlen(s) - (size_t)start);
	p = (char *)malloc(sizeof(*s) * (len + 1));
	if (!p)
	{
		return (NULL);
	}
	while (s[start] && j < len)
	{
		p[j] = s[start];
		j++;
		start++;
	}
	p[j] = '\0';
	return (p);
}
