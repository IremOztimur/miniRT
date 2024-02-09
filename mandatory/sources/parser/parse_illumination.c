/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_illumination.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:50:54 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/08 20:18:43 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_ambient_light(Light *ambient, char **tokens, int counters[3])
{
	char	**color;

	if (ft_matrix_size(tokens) != 3)
		return (ERROR("Wrong number of args in ambient (need 3)"), false);
	if (!parse_syntax(tokens, "001"))
		return (ERROR("Misconfiguration in commas/numbers in ambient"), false);
	if (!parse_rgb(tokens[2]))
		return (ERROR("Colors misformatting in ambient"), false);
	if (ft_atod(tokens[1]) < 0.0 || ft_atod(tokens[1]) > 1.0)
		return (ERROR("Ambient ratio out of bounds [0,1.0]"), false);
	color = ft_split(tokens[2], ',');
	ambient->ratio = ft_atod(tokens[1]);
	ambient->color = Color_from_strings(color);
	ft_matrix_delete(color, &free);
	counters[0]++;
	return (true);
}


bool	parse_camera(Camera *cam, char **tokens, int counters[3])
{
	char	**color;
	char	**normal;

	if (ft_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in camera (need 4)"), false);
	if (!parse_syntax(tokens, "0110"))
		return (ERROR("Misconfiguration in commas/numbers in camera"), false);
	color = ft_split(tokens[1], ',');
	normal = ft_split(tokens[2], ',');
	cam->center = Vector_from_string(color);
	cam->normal = Vector_from_string(normal);
	cam->normal = Vector_add(cam->normal, VEC_EPSILON);
	ft_matrix_delete(color, &free);
	ft_matrix_delete(normal, &free);
	if (Vector_magnitude(cam->normal) < 1.0 - EPSILON)
		return (ERROR("Normal vector is too small in camera"), false);
	cam->normal = Vector_normalize(cam->normal);
	cam->fov = ft_atod(tokens[3]);
	if (cam->fov < 0.0 || cam->fov > 180.0)
		return (ERROR("FOV out of bounds [0, 180]"), false);
	counters[1]++;
	return (true);
}

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3])
{
	char	**origin;
	char	**color;
	Light	*light;

	if (ft_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in light (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (ERROR("Misconfiguration in commas/numbers in light"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misformatting in light"), false);
	if (ft_atod(tokens[2]) < 0.0 || ft_atod(tokens[2]) > 1.0)
		return (ERROR("Light brightness out of bounds [0,1.0]"), false);
	origin = ft_split(tokens[1], ',');
	color = ft_split(tokens[3], ',');
	light = light_new(origin, tokens[2], color);
	ft_vector_push(lights, light);
	ft_matrix_delete(origin, &free);
	ft_matrix_delete(color, &free);
	counters[2]++;
	return (true);
}
