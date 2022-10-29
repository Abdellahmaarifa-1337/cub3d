/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/29 18:18:28 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub.h"
# include <math.h>

/*
  i === y
  j === x
*/

int		execute_MiniMap(t_cub *cub);
void	my_mlx_pixel_put(t_cub *cub, int x, int y, int color);

void set_horizontal_ray(t_cub * cub, int *ray);

void set_vertical_ray(t_cub * cub, int *ray);
int is_out(t_cub *cub ,int x, int y);
int is_ray_up(t_cub *cub);
int is_ray_right(t_cub *cub);
int is_wall_ray(t_cub *cub, int x, int y);
void set_rays(t_cub *cub);
int render_scene(t_cub *cub);
#endif