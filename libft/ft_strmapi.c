/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 20:40:28 by ioztimur          #+#    #+#             */
/*   Updated: 2022/12/14 20:40:30 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;

	i = 0;
	if (!s || !f)
	{
		return (0);
	}
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!arr)
	{
		return (0);
	}
	while (s[i] != '\0')
	{
		arr[i] = f(i, s[i]);
		i++;
	}
	arr[i] = 0;
	return (arr);
}
