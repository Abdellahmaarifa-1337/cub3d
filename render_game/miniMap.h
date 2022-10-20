/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/20 12:01:41 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub.h"
# include <math.h>
# define	MAP	cub->map
# define	PLY cub->p
/*
  i === y
  j === x
*/
# define EMPTY	0x494949
# define WALL	0xE1E6E6
# define PLAYER	0xF5DC50
# define CELL	60

int		execute_MiniMap(t_cub *cub);

#endif