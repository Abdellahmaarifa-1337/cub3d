/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:56:46 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/18 12:33:49 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_game_bonus.h"

int	get_color(t_img *img, int x, int y)
{
	char	*index;

	index = img->addr + (img->line_length * y + x * (img->bits_per_pixel / 8));
	return (*(int *)index);
}

int	get_color_from_texture(t_cub *cub, double y)
{
	float	newx;
	int		color;

	if (cub->is_ver == 1)
	{
		newx = (double)((int)cub->rays.y_ver % 64);
		if (cub->side == E)
			color = get_color(&(cub->textures[2]), newx, y * 64.0);
		else
			color = get_color(&(cub->textures[3]), newx, y * 64.0);
	}
	else
	{
		newx = (double)((int)cub->rays.x_hor % 64);
		if (cub->side == N)
			color = get_color(&(cub->textures[0]), newx, y * 64.0);
		else
			color = get_color(&(cub->textures[1]), newx, y * 64.0);
	}
	return (color);
}
