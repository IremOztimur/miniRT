/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:40:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/12 16:16:25 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

//TO-DO: add Doxygen for the functions below

bool	parse_syntax(char **tokens, char *code);

bool	parse_double(char **nb);

void	parse_map(Scene *scene, char **map, int counters[3]);

bool	parse_entity(Scene *scene, char **tokens, int count[3]);

bool	parse_rgb(char *color);

bool	parse_ambient_light(Light *ambient, char **tokens, int counters[3]);

bool	parse_camera(Camera *cam, char **tokens, int counters[3]);

bool	parse_light_source(t_vector *lights, char **tokens, int counters[3]);

Scene	*parse(char *filename);

char	**read_map(Scene *scene, char *filename);

bool	is_filename_valid(char *filename);

bool	parse_sphere(t_vector *shapes, char **tokens);

bool	parse_plane(t_vector *shapes, char **tokens);

bool	parse_cylinder(t_vector *shapes, char **tokens);
