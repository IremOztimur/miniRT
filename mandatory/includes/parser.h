/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:40:37 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/06 22:41:36 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

Scene	*parse(char *filename);

char	**read_map(Scene *scene, char *filename);

bool	is_filename_valid(char *filename);
