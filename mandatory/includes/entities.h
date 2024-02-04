/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iremoztimur <iremoztimur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:05:47 by iremoztimur       #+#    #+#             */
/*   Updated: 2024/02/04 23:09:08 by iremoztimur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIES_H
# define ENTITIES_H

#include "miniRT.h"

/**
 * @brief this function will create the scene struct and initialize
 * all members of the struct.
 *
 *
 * @return Scene struct with root information
 */
Scene		*Scene_create(void);

/**
 * @brief this function will destroy the scene struct and free all
 * members of the struct.
 *
 * @param Scene Scene struct with root information
 */
void		Scene_destroy(Scene **scene);

#endif
