/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightsource.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:49:13 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 19:42:34 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

Light	*light_new(char **c, char *ratio, char **cl)
{
	Light	*bulb;

	bulb = ft_calloc(1, sizeof(Light));
	if (!bulb)
		return (NULL);

	bulb->center = Vector_from_string(c);
	bulb->ratio = ft_atod(ratio);
	bulb->color = Color_from_strings(cl);

	return (bulb);
}

Light	*light_copy(Light *bulb)
{
	Light	*copy;

	copy = ft_calloc(1, sizeof(Light));
	if (!copy)
		return (NULL);
	*copy = *bulb;
	return (copy);
}
