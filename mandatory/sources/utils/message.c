/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:01:35 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/15 15:07:23 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	message(Scene *scene, char *text)
{
	Scene_destroy(&scene);
	printf("\033[1;31mERROR\033[0m\n%s\n", text);
	exit(EXIT_FAILURE);
}
