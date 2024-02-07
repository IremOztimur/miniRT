/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:04:59 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 13:05:56 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	ft_isnum(char *str, char *delims)
{
	if (*str == '-')
		++str;
	if (ft_strchr(delims, *str) || *str == '\0')
		return (false);
	while (*str && !ft_strchr(delims, *str))
		if (!ft_isdigit(*str++))
			return (false);
	return (true);
}
