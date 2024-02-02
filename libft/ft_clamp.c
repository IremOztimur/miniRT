/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:51:28 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/02 15:51:50 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_clamp(int n, int min, int max)
{
	if (n > max)
		return (max);
	else if (n < min)
		return (min);
	return (n);
}
