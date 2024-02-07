/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:52:42 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 12:54:11 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	power(int n, int power)
{
	long	res;

	res = n;
	while (power > 1)
	{
		res = res * n;
		power--;
	}
	return (res);
}

double	ft_atod(char *str)
{
	int			i;
	double		res;
	double		signal;

	i = 0;
	res = 0.0;
	signal = 1.0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signal = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	if (str[i] == '.')
		i++;
	str += i;
	res += (double)ft_atoi(str) / power(10, ft_strlen(str));
	return (signal * res);
}
