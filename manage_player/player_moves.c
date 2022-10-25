/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/25 12:10:01 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"
#include <math.h>


int is_wall(t_cub *cub, int x, int y)
{
	int px1, px2, py1, py2;

	px1 = (x - PLY_WIDTH / 2) / CELL;
	px2 = (x + PLY_WIDTH / 2) / CELL;
	py1 = (y - PLY_WIDTH / 2) / CELL;
	py2 = (y + PLY_WIDTH / 2) / CELL;
	if (cub->map.data[y / CELL][px1] == '1' || cub->map.data[y / CELL][px2] == '1'
	|| cub->map.data[py1][x / CELL] == '1' || cub->map.data[py2][x / CELL] == '1')
		return (1);
	return (0);

}

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
	dx = cos(pa);
	dy = sin(pa);
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
	dx = cos(pa);
	dy = sin(pa);

	if (!is_wall(cub, PLY.x + dx, PLY.y + dy))
	{
		PLY.x += dx;
		PLY.y += dy;
	}
}
     
void	look_right(t_cub *cub)
{
	PLY.pa += INC_PA;
	if (PLY.pa > (2 * PI))
		PLY.pa -= (2 * PI);
	PLY.dx += cos(PLY.pa);
	PLY.dy += sin(PLY.pa);
}

void	look_left(t_cub *cub)
{   
	PLY.pa -= INC_PA;
	if (PLY.pa < 0)
		PLY.pa += (2 * PI);
	PLY.dx += cos(PLY.pa);
	PLY.dy += sin(PLY.pa);
}

int	player_moves(int keycode, t_cub *cub)
{
	if (keycode == 13)
		move_up(cub);
	else if (keycode == 1)
		move_down(cub);
	else if (keycode == 2)
		move_right(cub);
	else if (keycode == 0)
		move_left(cub);
	else if (keycode == 124)
		look_right(cub);
	else if (keycode == 123)
		look_left(cub);
	else if (keycode == 53)
		exit(0);
	return (0);
}
