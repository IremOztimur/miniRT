/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:18:15 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/18 04:17:48 by iremoztimur      ###   ########.fr       */
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

int	quit(Scene *scene)
{
	Scene_destroy(&scene);
	exit(EXIT_SUCCESS);
}

int	on_keypress(int keycode, Scene *s)
{
	if (keycode == ESC)
		quit(s);
	else if (keycode == W)
		s->camera.center.y += 5;
	else if (keycode == A)
		s->camera.center.x -= 5;
	else if (keycode == S)
		s->camera.center.y -= 5;
	else if (keycode == D)
		s->camera.center.x += 5;
	else if (keycode == C)
		s->camera.center.z -= 5;
	else if (keycode == V)
		s->camera.center.z += 5;
	render(s);
	return (keycode);
}

int	main(int argc, char **av)
{
	Scene *scene;

	if (argc != 2)
		message(NULL, ERROR_USAGE);
	scene = parse(av[1]);
	init_viewport(scene);
	init_graphics(scene);
	mlx_hook(scene->disp.win, KeyPress, KeyPressMask, on_keypress, scene);
	mlx_hook(scene->disp.win, DestroyNotify, StructureNotifyMask, quit, scene);
	render(scene);
	mlx_loop(scene->disp.mlx);
}
