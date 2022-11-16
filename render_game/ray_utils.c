/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:10:49 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/13 13:46:15 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_game.h"

int	is_out(t_cub *cub, int x, int y)
{
	if (y < 0 || (size_t)y >= cub->map.height * CELL)
		return (1);
	if (x < 0 || (size_t)x >= cub->map.width * CELL)
		return (1);
	return (0);
}

int	is_ray_up(t_cub *cub)
{
	if (cub->map.ray_pa > 0 && cub->map.ray_pa < PI)
		return (0);
	return (1);
}

int	is_ray_right(t_cub *cub)
{
	if (cub->map.ray_pa > PI / 2 && cub->map.ray_pa < 3 * PI / 2)
		return (0);
	return (1);
}

int	is_wall_ray(t_cub *cub, float x, float y)
{
	int	mapx;
	int	mapy;

	mapx = (int)(((y) / (float)CELL));
	mapy = (int)(((x) / (float)CELL));
	if (cub->map.data[mapx][mapy] == '1')
		return (1);
	return (0);
}
