/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/25 00:42:07 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub.h"
# include <math.h>


# define PRUPLE     0xFB2576
# define EMPTY	    0x494949
# define WALL		    0xE1E6E6
# define PLAYER	    0xF5DC50
# define LINE		    0xFF7D2D
# define CELL		    52
# define PLY_WIDTH  CELL/6
# define INC_PA     0.01

# define	PI		3.14159265359

/*
  i === y
  j === x
*/

int		execute_MiniMap(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);

#endif