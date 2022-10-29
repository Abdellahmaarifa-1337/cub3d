/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:29:08 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/29 13:32:18 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"

int	mouse_switcher(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1 && !cub->mouse_on)
	{
		cub->mouse_on = 1;
		// mlx_mouse_hide();
	}
	else if (button == 1 && cub->mouse_on)
	{
		cub->mouse_on = 0;
		// mlx_mouse_show();
	}
	return (0);
}

int	mouse_hook(int x, int y, t_cub *cub)
{
	int	sign;

	(void)y;
	sign = 0;
	if (x < cub->prev_x_mouse)
		sign = -1;
	else if (x > cub->prev_x_mouse)
		sign = 1;
	if (cub->mouse_on)
	{
		if (sign > 0)
		{
			PLY.pa += PLY.inc_pa;
			if (PLY.pa > 2 * PI)
				PLY.pa -= (2 * PI);
			PLY.dx += cos(PLY.pa) * 5;
			PLY.dy += sin(PLY.pa) * 5;
		}
		else if (sign < 0)
		{
			PLY.pa -= PLY.inc_pa;
			if (PLY.pa < 0)
				PLY.pa += (2 * PI);
			PLY.dx += cos(PLY.pa) * 5;
			PLY.dy += sin(PLY.pa) * 5;
		}
	}
	cub->prev_x_mouse = x;
	return (0);
}
