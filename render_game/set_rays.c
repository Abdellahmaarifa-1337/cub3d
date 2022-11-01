/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:13:33 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/01 11:42:06 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"


// void	save_ray(t_cub *cub, double an, int index)
// {
// 	double		ray_h[2];
// 	double		ray_v[2];
// 	double		dist_h;
// 	double		dist_v;

// 	cub->map.ray_pa = an;
// 	if (cub->map.ray_pa < 0)
// 		cub->map.ray_pa += 2 * PI;
// 	else if (cub->map.ray_pa > 2*PI)
// 		cub->map.ray_pa -= 2 * PI;
	
// 	set_vertical_ray(cub, ray_v);
// 	set_horizontal_ray(cub, ray_h);
	
// 	//dist_h = (double)fabs((PLY.x - (double)ray_h[0]) / cos(fabs(an)));
// 	//dist_v = (double)fabs((PLY.x - (double)ray_v[0]) / cos(fabs(an)));
// 	dist_h = (sqrt((ray_h[0] - PLY.x)*(ray_h[0] - PLY.x) + (ray_h[1] - PLY.y) * (ray_h[1] - PLY.y)));
// 	dist_v = (sqrt((ray_v[0] - PLY.x)*(ray_v[0] - PLY.x) + (ray_v[1] - PLY.y) * (ray_v[1] - PLY.y)));

// 	if (dist_v <= dist_h || (ray_h[0] == -1 && ray_h[1] == -1))
// 	{
// 		cub->rays[index].ray_dist = dist_v;
// 		cub->rays[index].x = ray_v[0];
// 		cub->rays[index].y = ray_v[1];
// 		cub->rays[index].is = 1;
// 	}
// 	else if (dist_v > dist_h || (ray_v[0] == -1 && ray_v[1] == -1 )) 
// 	{
// 		cub->rays[index].ray_dist = dist_h;
// 		cub->rays[index].x = ray_h[0];
// 		cub->rays[index].y = ray_h[1];
// 		cub->rays[index].is = -1;
// 	}
// }



// void set_rays(t_cub *cub)
// {
// 	double	dp;
// 	double	an;
// 	int		index;

// 	dp = (float)(PI / (3.0 * (float)WIN_WIDHT));
// 	an = PLY.pa - PI / 6;
// 	index = 0;
// 	// cub->rays[0].pa= PLY.pa;
// 	// save_ray(cub, PLY.pa, index);
// 	// return ;
// 	while (an < PLY.pa + PI / 6)
// 	{
		
// 		cub->rays[index].pa= an;
// 		//save_ray_tmp(cub, an, index);
// 		save_ray(cub, an, index);
// 		// test
// 		// if (index > 500)
// 		// 	break ;
// 		// end test
// 		index++;
// 		an += dp;
// 	}
// 	//exit(1);

// }