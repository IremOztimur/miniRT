/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:18:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/10 14:53:57 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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

int	main(int argc, char **av)
{
	Scene *scene = Scene_create();

	if (argc != 2)
		message(NULL, ERROR_USAGE);
	scene = parse(av[1]);
	init_viewport(scene);
	init_graphics(scene);
	render(scene);
	mlx_loop(scene->disp.mlx);
}
