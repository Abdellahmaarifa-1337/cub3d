/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:56:46 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 12:36:34 by amaarifa         ###   ########.fr       */
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

int	get_color_from_textuer(t_cub *cub, double x, double y)
{
	// load image
	//printf("%s\n", cub->textuers->addr);
	//return WALL;
	float newx, newy;
	// if intersection is vertical or hor 
	if (cub->inter.is_ver == 1)
		newx = (double)(cub->inter.inter_v % 32) / 32.0;
	else
		newx = (double)(cub->inter.inter_h % 32) / 32.0;
	return (get_color(&(cub->textuers), newx * 32.0, y * 32.0));
}