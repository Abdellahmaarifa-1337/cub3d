/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/18 18:55:16 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_GAME_H
# define RENDER_GAME_H

# include "../cub_bonus.h"
# include <math.h>

int		execute_minimap(t_cub *cub);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

double	set_horizontal_ray(t_cub *cub);
double	set_vertical_ray(t_cub *cub);
int		is_out(t_cub *cub, int x, int y);
int		is_ray_up(t_cub *cub);
int		is_ray_right(t_cub *cub);
int		is_wall_ray(t_cub *cub, float x, float y);
void	set_rays(t_cub *cub);
int		render_scene(t_cub *cub);
void	my_mlx_clear_image(t_img *img, int height, int width);
double	get_ray_dist(t_cub *cub);
int		get_color_from_texture(t_cub *cub, double y);
void	init_textures(t_cub *cub, int *d);
void	init_mlx(t_cub *cub);
void	initializing_keys(t_cub *cub);

int		rgb_to_int(int r, int g, int b);
void	throw_error(const char *error, int _ex);

float	get_dist(t_cub *cub, float x, float y);
void	put_pixels(t_cub *cub, float begin[2], int px_line);

#endif