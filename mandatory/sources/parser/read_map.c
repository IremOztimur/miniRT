/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:27:36 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/08 19:20:28 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

bool	is_filename_valid(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 3)
		return (false);
	return (ft_strnstr(filename + (len - 3), ".rt", len) != NULL);
}

int	get_filesize(Scene *scene, char *filename)
{
	int		fd;
	int		counter;
	char	*line;

	counter = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(scene, ERROR_OPEN_FILE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] != '\n')
			counter++;
		free(line);
	}
	close(fd);
	return (counter);
}

char	**read_map(Scene *scene, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	**map;

	i = 0;
	map = ft_matrix_new(get_filesize(scene, filename), 0);
	if (!map)
		message(scene, ERROR_MALLOC("read_map"));
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		message(scene, ERROR_OPEN_FILE);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strchr("\n#", line[0]))
			map[i++] = line;
		else
			free(line);
	}
	close(fd);
	return (map);
}
