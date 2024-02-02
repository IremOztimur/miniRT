/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:51:36 by ioztimur          #+#    #+#             */
/*   Updated: 2022/10/18 17:21:22 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	sizeinbytes;

	sizeinbytes = ft_strlen(s1) + 1 * sizeof(char);
	s2 = malloc(sizeinbytes);
	if (!s2)
	{
		return (NULL);
	}
	if (s1 != NULL)
	{
		ft_memcpy(s2, s1, sizeinbytes);
	}
	return (s2);
}
