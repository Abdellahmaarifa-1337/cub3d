/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:56:46 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/11 10:36:56 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

int get_color(t_img *img, int x, int y)
{
	//return WALL;
	char *index = img->addr + (img->line_length * y + x * (img->bits_per_pixel / 8));
	//printf("%d\n", *(int *)index);
	return (*(int *)index);
};

int	get_color_from_texture(t_cub *cub, double rx, double ry, double y)
{
	float	newx;
	int		color;
	
	if (cub->inter.is_ver == 1)
	{
		newx = (double)(cub->inter.inter_v % 64) / 64.0;
		if (cub->side == E)
			color = get_color(&(TEX[2]), newx * 64.0, y * 64.0);
		else
			color = get_color(&(TEX[3]), newx * 64.0, y * 64.0);
	}
	else
	{
		newx = (double)(cub->inter.inter_h % 64) / 64.0;
		if (cub->side == N)
			color = get_color(&(TEX[0]), newx * 64.0, y * 64.0);
		else
			color = get_color(&(TEX[1]), newx * 64.0, y * 64.0);
	}
	// printf("(%d , %d)\n", (int)rx, (int)ry);
	// while(1);
	return (color);
}
