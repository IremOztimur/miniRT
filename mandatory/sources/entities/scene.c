/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:05:05 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/05 18:59:47 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/entities.h"

// TO-DO: Shapes and lights will be created as well
Scene		*Scene_create(void)
{
	Scene *scene;

	scene = ft_calloc(1, sizeof(Scene));
	if (!scene)
		return (NULL);
	

	return (scene);
}

void		Scene_destroy(Scene **scene)
{
	if (!(*scene))
		return ;
	if ((*scene)->disp.img)
		mlx_destroy_image((*scene)->disp.mlx, (*scene)->disp.img);
	if ((*scene)->disp.win)
		mlx_destroy_window((*scene)->disp.mlx, (*scene)->disp.win);
	ft_free((*scene)->disp.mlx);
	free(*scene);
	*scene = NULL;
}
