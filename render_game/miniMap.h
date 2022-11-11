/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/11 10:36:56 by mkabissi         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

double	set_horizontal_ray(t_cub * cub);
double	set_vertical_ray(t_cub * cub);
int     is_out(t_cub *cub ,int x, int y);
int     is_ray_up(t_cub *cub);
int     is_ray_right(t_cub *cub);
int     is_wall_ray(t_cub *cub, float x, float y);
void	set_rays(t_cub *cub);
int		render_scene(t_cub *cub);

void	my_mlx_clear_image(t_img *img, int height, int width);
void	init_rays(t_cub *cub);
double	get_ray_dist(t_cub *cub);
int		get_color_from_texture(t_cub *cub, double rx, double ry, double y);
#endif