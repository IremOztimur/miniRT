/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 21:57:18 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/06 23:51:27 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/parser.h"

bool parse_entity(Scene *scene, char **tokens, int count[3])
{
	//TO-DO: Parse "A", "C", "L", "sp", | later: "pl", "cy"
	if (!(ft_strncmp("A", )))
}

void	parse_map(Scene *scene, char **map, int counters[3])
{
	int		i;
	bool	ok;
	char	**tokens;

	i = -1;
	while (map[++i])
	{
		tokens = ft_split(map[i], ' ');
		ok = parse_entity(scene, tokens, counters);
		ft_matrix_delete(tokens, &free);
		if (!ok)
			message(scene, ERROR_SYNTAX);
	}
}

Scene *parse(char *filename)
{
	Scene *scene;
	int	counters[3];

	ft_bzero(counters, 3);
	if (!(is_filename_valid(filename)))
		message(NULL, ERROR_NOT_RT);
	scene = Scene_create();
	if (!scene)
		message(NULL, ERROR_MALLOC("Scene struct"));
	scene->map = read_map(scene, filename);
	if (ft_matrix_size(scene->map) == 0)
		message(NULL, ERROR_EMPTY_MAP);
	//TO-DO: parse the map
	//parse_map();

}
