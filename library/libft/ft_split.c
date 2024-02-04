/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ioztimur <ioztimur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 19:07:06 by iremoztimur       #+#    #+#             */
/*   Updated: 2022/12/24 19:47:38 by ioztimur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcounter(char const *s, char c)
{
	unsigned int	i;
	int				counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			counter++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	size_t	i;

	if (!s1)
	{
		return (NULL);
	}
	ptr = (char *)malloc(sizeof(char) * n + 1);
	if (!ptr)
	{
		return (NULL);
	}
	i = 0;
	while (s1 && i < n)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		a;

	i = 0;
	a = 0;
	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (wordcounter(s, c) + 1));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			arr[a++] = ft_strndup(s + j, i - j);
	}
	arr[a] = 0;
	return (arr);
}
