/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/13 21:02:28 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"
#include <math.h>

void	move_up(t_cub *cub)
{
	if (!is_wall(cub, cub->p.dx, cub->p.dy))
	{
		cub->p.x += cub->p.dx;
		cub->p.y += cub->p.dy;
	}
}

void	move_down(t_cub *cub)
{
	if (!is_wall(cub, -cub->p.dx, -cub->p.dy))
	{
		cub->p.x -= cub->p.dx;
		cub->p.y -= cub->p.dy;
	}
}

void	move_right(t_cub *cub)
{
	float	dx;
	float	dy;
	float	pa;

	pa = cub->p.pa + PI / 2;
	if (pa > (2 * PI))
		pa -= (2 * PI);
	dx = cos(pa) * 5;
	dy = sin(pa) * 5;
	if (!is_wall(cub, dx, dy))
	{
		cub->p.x += dx;
		cub->p.y += dy;
	}
}

void	move_left(t_cub *cub)
{
	float	dx;
	float	dy;
	float	pa;

	pa = cub->p.pa - PI / 2;
	if (pa < 0)
		pa += (2 * PI);
	dx = cos(pa) * 5;
	dy = sin(pa) * 5;
	if (!is_wall(cub, dx, dy))
	{
		cub->p.x += dx;
		cub->p.y += dy;
	}
}
