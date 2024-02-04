/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:18:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 11:27:28 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

void	nc_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	destroy_world(Scene **world)
{
	if (!(*world))
		return ;
	if ((*world)->disp.img)
		mlx_destroy_image((*world)->disp.mlx, (*world)->disp.img);
	if ((*world)->disp.win)
		mlx_destroy_window((*world)->disp.mlx, (*world)->disp.win);
	if ((*world)->disp.mlx)
		mlx_destroy_display((*world)->disp.mlx);
	nc_free((*world)->disp.mlx);
	free(*world);
	*world = NULL;
}

void	message(Scene *scene, char *text)
{
	destroy_world(&scene);
	printf("Error\n%s\n", text);
	exit(EXIT_FAILURE);
}

void	init_graphics(Scene *w)
{
	w->disp.mlx = mlx_init();
	if (!w->disp.mlx)
		message(w, ERROR_MALLOC("init_graphics (mlx)"));
	w->disp.win = mlx_new_window(w->disp.mlx, WIDTH, HEIGHT, "miniRT");
	if (!w->disp.win)
		message(w, ERROR_MALLOC("init_graphics (mlx window)"));
	w->disp.img = mlx_new_image(w->disp.mlx, WIDTH, HEIGHT);
	if (!w->disp.img)
		message(w, ERROR_MALLOC("init_graphics (mlx image)"));
	w->disp.addr = mlx_get_data_addr(w->disp.img, &w->disp.bpp, \
		&w->disp.line_length, &w->disp.endian);
	if (!w->disp.addr)
		message(w, ERROR_MALLOC("init_graphics (mlx image address)"));
}



int	main(void)
{
	Scene *scene;
	init_graphics(scene);
}
