/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:39:33 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/14 11:20:15 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_sphere(t_vector *shapes, char **tokens)
{
	bool		ok;
	Sphere		sphere;
	t_shape		*shape;

	if (ft_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in sphere (need 4)"), false);
	if (!parse_syntax(tokens, "0101"))
		return (ERROR("Misconfiguration in commas/numbers in sphere"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misforma*tting in sphere"), false);
	ok = sphere_from_strings(&sphere, tokens);
	if (!ok)
		return (ERROR("Values are too small in sphere"), false);
	shape = shape_new(&sphere, SPHERE, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}

bool	parse_plane(t_vector *shapes, char **tokens)
{
	bool	ok;
	Plane	plane;
	t_shape	*shape;

	if (ft_matrix_size(tokens) != 4)
		return (ERROR("Wrong number of args in plane (need 4)"), false);
	if (!parse_syntax(tokens, "0111"))
		return (ERROR("Misconfiguration in commas/numbers in plane"), false);
	if (!parse_rgb(tokens[3]))
		return (ERROR("Colors misformatting in plane"), false);
	ok = plane_from_strings(&plane, tokens);
	if (!ok)
		return (ERROR("Values are too small in plane"), false);
	shape = shape_new(&plane, PLANE, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}


bool parse_cylinder(t_vector *shapes, char **tokens)
{
	bool		ok;
	Cylinder	cylinder;
	t_shape		*shape;

	if (ft_matrix_size(tokens) != 6)
		return (ERROR("Wrong number of args in cylinder (need 6)"), false);
	if (!parse_syntax(tokens, "011001"))
		return (ERROR("Misconfiguration in commas/numbers in cylinder"), false);
	if (!parse_rgb(tokens[5]))
		return (ERROR("Colors misformatting in cylinder"), false);
	ok = cylinder_from_strings(&cylinder, tokens);
	if (!ok)
		return (ERROR("Values are too small in cylinder"), false);
	shape = shape_new(&cylinder, CYLINDER, shapes->size);
	ft_vector_push(shapes, shape);
	return (true);
}

