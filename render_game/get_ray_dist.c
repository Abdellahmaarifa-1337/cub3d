/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ray_dist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 11:26:18 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/01 11:40:18 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

double	get_ray_dist(t_cub *cub)
{
	double		dist_h;
	double		dist_v;

	if (cub->map.ray_pa < 0)
		cub->map.ray_pa += 2 * PI;
	else if (cub->map.ray_pa > 2*PI)
		cub->map.ray_pa -= 2 * PI;
	dist_v = set_vertical_ray(cub);
	dist_h = set_horizontal_ray(cub);
	is_ver = 0;
	if (dist_h <= dist_v)
		return (dist_h * fabs(cos(fabs(PLY.pa - cub->map.ray_pa))));
	is_ver = 1;
	return (dist_v * fabs(cos(fabs(PLY.pa - cub->map.ray_pa))));
}