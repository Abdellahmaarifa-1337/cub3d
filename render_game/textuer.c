/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textuer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:56:46 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/01 18:47:37 by amaarifa         ###   ########.fr       */
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

int	get_color_from_textuer(t_cub *cub, int x, int y)
{
	// load image
	//return WALL;
	float newx, newy;

	newx = (float)((float)x / 32.0) - (int)(x / 32); 
	newy = (float)((float)y / 32.0) - (int)(y / 32); 
	//return WALL;
	return (get_color((cub->textuers), 0, 0));
}