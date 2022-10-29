/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/26 22:41:32 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"
#include <math.h>

void	move_up(t_cub *cub)
{
	if (!is_wall(cub, PLY.x + PLY.dx, PLY.y + PLY.dy))
	{
		PLY.x += PLY.dx;
		PLY.y += PLY.dy;
	}
}

void	move_down(t_cub *cub)
{
	if (!is_wall(cub, PLY.x - PLY.dx, PLY.y - PLY.dy))
	{
		PLY.x -= PLY.dx;
		PLY.y -= PLY.dy;
	}
}

void	move_right(t_cub *cub)
{
	float	dx;
	float	dy;
	float	pa;

	pa = PLY.pa + PI / 2;
	if (pa > (2 * PI))
		pa -= (2 * PI);
	dx = cos(pa) * 5;
	dy = sin(pa) * 5;
	if (!is_wall(cub,  PLY.x + dx, PLY.y + dy))
	{
		PLY.x += dx;
		PLY.y += dy;
	}
}

void	move_left(t_cub *cub)
{
	float	dx;
	float	dy;
	float	pa;

	pa = PLY.pa - PI / 2;
	if (pa < 0)
		pa += (2 * PI);
	dx = cos(pa) * 5;
	dy = sin(pa) * 5;

	if (!is_wall(cub, PLY.x + dx, PLY.y + dy))
	{
		PLY.x += dx;
		PLY.y += dy;
	}
}
