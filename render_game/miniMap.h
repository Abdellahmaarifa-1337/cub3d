/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/22 19:06:53 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub.h"
# include <math.h>

# define EMPTY	0x494949
# define WALL		0xE1E6E6
# define PLAYER	0xF5DC50
# define LINE		0xFF7D2D
# define CELL		65

# define	PI		3.14159265359

/*
  i === y
  j === x
*/

int		execute_MiniMap(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);

#endif