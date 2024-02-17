/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 11:46:02 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/07 13:18:00 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_syntax(char **tokens, char *code)
{
	int		i;
	bool	ok;
	int		numbers_size;
	char	**numbers;

	i = -1;
	ok = true;
	while (tokens[++i])
	{
		numbers = ft_split(tokens[i], ',');
		numbers_size = ft_matrix_size(numbers);
		if (code[i] == HAS_COMMAS)
			ok = (ft_count(tokens[i], ',') == 2 && numbers_size == 3);
		else
			ok = (ft_count(tokens[i], ',') == 0);
		if (!parse_double(numbers) && i > 0)
			ok = false;
		ft_matrix_delete(numbers, &free);
		if (!ok)
			return (false);
	}
	return (true);
}

bool	parse_double(char **nb)
{
	int		i;
	char	*tmp;

	i = -1;
	while (nb[++i])
	{
		if (!ft_isnum(nb[i], ".\n") || ft_strclen(nb[i], ".") == 0)
			return (false);
		tmp = ft_strchr(nb[i], '.');
		if (tmp && (*(tmp + 1) == '\0' || !ft_isnum(tmp + 1, "\n")))
			return (false);
	}
	return (true);
}

bool	parse_rgb(char *color)
{
	int		i;
	bool	ok;
	char	**tokens;

	i = -1;
	ok = true;
	tokens = ft_split(color, ',');
	if (!tokens)
		return (false);
	while (tokens[++i])
	{
		if (!ft_isnum(tokens[i], "\n"))
			ok = false;
		if (ft_atoi(tokens[i]) < 0 || ft_atoi(tokens[i]) > 255)
			ok = false;
		if (!ok)
			break ;
	}
	ft_matrix_delete(tokens, &free);
	return (ok);
}
