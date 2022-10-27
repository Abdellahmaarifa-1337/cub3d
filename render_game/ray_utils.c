/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:10:49 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/27 03:26:30 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniMap.h"

int is_out(t_cub *cub ,int x, int y)
{
	if (y < 0 || (size_t)y  >= MAP.height * CELL)
			return (1);
	if (x < 0 || (size_t)x >= MAP.width * CELL)
			return (1);
	return (0);
}

int is_ray_up(t_cub *cub)
{

	if (cub->map.ray_pa > 0 && cub->map.ray_pa < PI)
		return (0);
	return (1);
}

int is_ray_right(t_cub *cub)
{
	if (cub->map.ray_pa > PI/2 && cub->map.ray_pa < 3 * PI/2)
		return (0);
	return (1);
}

int is_wall_ray(t_cub *cub, int x, int y)
{

	// printf("x: %d\ty: %d\n", (int)((x - 5) / CELL), (int)((y - 5) / CELL));
	if (cub->map.data[(int)(y / CELL)][(int)(x / CELL)] == '1')
		return 1;
	if ( is_ray_up(cub) &&  !is_ray_right(cub)
		&& cub->map.data[(int)((y) / CELL)][(int)((x + 5) / CELL)] == '1'
		&& cub->map.data[(int)((y + 5) / CELL)][(int)((x - 5) / CELL)] == '1')
		return 1;
	if ( !is_ray_up(cub) && !is_ray_right(cub)
		&& cub->map.data[(int)((y - 5) / CELL)][(int)((x) / CELL)] == '1'
		&& cub->map.data[(int)((y + 5) / CELL)][(int)((x + 5) / CELL)] == '1')
		return 1;
	if ( !is_ray_up(cub) &&  is_ray_right(cub)
		&& cub->map.data[(int)((y - 5) / CELL)][(int)((x) / CELL)] == '1'
		&& cub->map.data[(int)((y + 5) / CELL)][(int)((x - 5) / CELL)] == '1')
		return 1;
	if ( is_ray_up(cub) && is_ray_right(cub)
		&& cub->map.data[(int)((y - 5) / CELL)][(int)((x - 5) / CELL)] == '1'
		&& cub->map.data[(int)((y + 5) / CELL)][(int)((x + 5) / CELL)] == '1')
			return 1;
	return (0);
}