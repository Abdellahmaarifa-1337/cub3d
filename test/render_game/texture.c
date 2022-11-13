/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:56:46 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/13 21:56:39 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_game.h"

int	get_color(t_img *img, int x, int y)
{
	char	*index;

	index = img->addr + (img->line_length * y + x * (img->bits_per_pixel / 8));
	return (*(int *)index);
}

int	get_color_from_texture(t_cub *cub, double rx, double ry, double y)
{
	float	newx;
	int		color;

	if (cub->is_ver == 1)
	{
		newx = (double)((int)cub->rays.y_ver % 64) / 64.0;
		if (cub->side == E)
			color = get_color(&(cub->textures[2]), newx * 64.0, y * 64.0);
		else
			color = get_color(&(cub->textures[3]), newx * 64.0, y * 64.0);
	}
	else
	{
		newx = (double)((int)cub->rays.x_hor % 64) / 64.0;
		if (cub->side == N)
			color = get_color(&(cub->textures[0]), newx * 64.0, y * 64.0);
		else
			color = get_color(&(cub->textures[1]), newx * 64.0, y * 64.0);
	}
	return (color);
}
