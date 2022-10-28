/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:13:33 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/28 18:26:25 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"


void	save_ray(t_cub *cub, float an, int index)
{
	int		ray_h[2];
	int		ray_v[2];
	int		dist_h;
	int		dist_v;

	cub->map.ray_pa = an;
	if (cub->map.ray_pa < 0)
		cub->map.ray_pa += 2 * PI;
	else if (cub->map.ray_pa > 2*PI)
		cub->map.ray_pa -= 2 * PI;
	
	set_vertical_ray(cub, ray_v);
	set_horizontal_ray(cub, ray_h);
	dist_h = sqrt((ray_h[0] - PLY.x)*(ray_h[0] - PLY.x) + (ray_h[1] - PLY.y) * (ray_h[1] - PLY.y));
	dist_v = sqrt((ray_v[0] - PLY.x)*(ray_v[0] - PLY.x) + (ray_v[1] - PLY.y) * (ray_v[1] - PLY.y));
	if (dist_v < dist_h)
	{
		cub->rays[index].ray_dist = dist_v;
		cub->rays[index].x = ray_v[0];
		cub->rays[index].y = ray_v[1];
	}
	else
	{
		cub->rays[index].ray_dist = dist_h;
		cub->rays[index].x = ray_h[0];
		cub->rays[index].y = ray_h[1];
	}
	if (ray_h[0] == -1 && ray_h[1] == -1)
	{
		cub->rays[index].ray_dist = dist_v;
		cub->rays[index].x = ray_v[0];
		cub->rays[index].y = ray_v[1];
	}
	if (ray_v[0] == -1 && ray_v[1] == -1)
	{
		cub->rays[index].ray_dist = dist_h;
		cub->rays[index].x = ray_h[0];
		cub->rays[index].y = ray_h[1];
	}
}

void set_rays(t_cub *cub)
{
	float	dp;
	float	an;
	int		index;

	dp = (float)(PI / (3.0 * (float)WIN_WIDHT));
	an = PLY.pa - PI / 6;
	index = 0;
	while (an < PLY.pa + PI / 6)
	{
		cub->rays[index].pa= an;
		save_ray(cub, an, index);
		index++;
		an += dp;
	}
}