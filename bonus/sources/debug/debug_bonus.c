/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:15:58 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/17 19:23:07 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	ambient_print(Light *s)
{
	printf("Ambient:\n");
	printf("  Ratio: (%.02f)\n", s->ratio);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}

void	camera_print(Camera *c)
{
	printf("Camera:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: %.4lf, %.4lf, %.4lf\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Fov: %2.f\n", c->fov);
}

void	light_print(Light *l)
{
	printf("Lightsource:\n");
	printf("  Point: (%.4lf, %.4lf, %.4lf)\n", \
		l->center.x, l->center.y, l->center.z);
	printf("  Ratio: %.4lf\n", l->ratio);
	printf("  Color: (%d, %d, %d)\n", l->color.r, l->color.g, l->color.b);
}

void	color_print(Color *color)
{
	printf("#%02X%02X%02X\n", color->r, color->g, color->b);
}

void	vector_print(Vector vec)
{
	printf("Vec: (x, y, z) = (%.4lf, %.4lf, %.4lf)\n", vec.x, vec.y, vec.z);
}

void	sphere_print(Sphere *s)
{
	printf("Sphere:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		s->center.x, s->center.y, s->center.z);
	printf("  Radius: %.4lf\n", s->radius);
	printf("  Color: (%d, %d, %d)\n", s->color.r, s->color.g, s->color.b);
}

void	plane_print(Plane *p)
{
	printf("Plane:\n");
	printf("  Point: %.4lf, %.4lf, %.4lf\n", \
		p->center.x, p->center.y, p->center.z);
	printf("  Normal: %.4lf, %.4lf, %.4lf\n", \
		p->normal.x, p->normal.y, p->normal.z);
	printf("  Color: (%d, %d, %d)\n", p->color.r, p->color.g, p->color.b);
}

void	cylinder_print(Cylinder *c)
{
	printf("Cylinder:\n");
	printf("  Center: (%.4lf, %.4lf, %.4lf)\n", \
		c->center.x, c->center.y, c->center.z);
	printf("  Normal: (%.4lf, %.4lf, %.4lf)\n", \
		c->normal.x, c->normal.y, c->normal.z);
	printf("  Radius: %.4lf\n", c->radius);
	printf("  Height: %.4lf\n", c->height);
	printf("  Color: (%d, %d, %d)\n", c->color.r, c->color.g, c->color.b);
}

void	ft_vector_print(t_vector *vector)
{
	uint32_t	i;

	if (!vector)
		return ;
	i = -1;
	while (++i < vector->size)
		(*vector->print)(vector->array[i]);
}

void	scene_print(Scene *scene)
{
	printf("\n\t================ DEBUG ================\n\n");
	ambient_print(&scene->ambient);
	camera_print(&scene->camera);
	ft_vector_print(scene->lights);
	ft_vector_print(scene->shapes);
	printf("Right Vector:\n  ");
	vector_print(scene->right);
	printf("Up Vector:\n  ");
	vector_print(scene->up);
	printf("Viewport:\n");
	printf("  Height: %lf\n", scene->hview);
	printf("  Width: %lf\n", scene->wview);
	printf("\n\t=======================================\n\n");
}

void	shape_print(t_shape *shape)
{
	if (shape->type == PLANE)
		plane_print(&shape->data.pl);
	else if (shape->type == SPHERE)
		sphere_print(&shape->data.sp);
	else if (shape->type == CYLINDER)
		cylinder_print(&shape->data.cy);
	printf("  ID: %d\n", shape->id);
	printf("  Specular Coefficient (Ks): %lf\n", shape->sp_ratio);
	printf("  Shininess (n): %lf\n", shape->shininess);
}
