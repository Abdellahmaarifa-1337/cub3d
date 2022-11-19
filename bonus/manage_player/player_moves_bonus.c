/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/18 19:11:22 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player_bonus.h"
#include <math.h>

void	collisions(t_cub *cub, float dx, float dy)
{
	if (cub->p.pa != (float)((3 * PI) / 2) && cub->p.pa != (float)(PI / 2)
		&& !is_wall(cub, dx, 0))
		cub->p.x += dx;
	else if (cub->p.pa != 0 && cub->p.pa != (float)PI && !is_wall(cub, 0, dy))
		cub->p.y += dy;
}

void	move_up(t_cub *cub)
{
	if (!is_wall(cub, cub->p.dx, cub->p.dy))
	{
		cub->p.x += cub->p.dx;
		cub->p.y += cub->p.dy;
	}
	else
		collisions(cub, cub->p.dx, cub->p.dy);
}

void	move_down(t_cub *cub)
{
	if (!is_wall(cub, -cub->p.dx, -cub->p.dy))
	{
		cub->p.x -= cub->p.dx;
		cub->p.y -= cub->p.dy;
	}
	else
		collisions(cub, -cub->p.dx, -cub->p.dy);
}

void	move_right(t_cub *cub)
{
	float	dx;
	float	dy;
	float	pa;

	pa = cub->p.pa + PI / 2;
	if (pa > (2 * PI))
		pa -= (2 * PI);
	dx = cos(pa) * 2;
	dy = sin(pa) * 2;
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
	dx = cos(pa) * 2;
	dy = sin(pa) * 2;
	if (!is_wall(cub, dx, dy))
	{
		cub->p.x += dx;
		cub->p.y += dy;
	}
}
