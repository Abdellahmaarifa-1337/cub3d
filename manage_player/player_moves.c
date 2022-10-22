/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/22 17:31:14 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"
#include <math.h>

int is_wall(t_cub *cub, int dx, int dy, int not)
{
	int xcell;
	int ycell;
	float	pa;

	// test up
	xcell = ((PLY.x + (PLY.dx - CELL / 12)) / CELL);
	ycell = ((PLY.y	+ (PLY.dy - CELL / 12)) / CELL);
	if (cub->map.data[ycell][xcell] == '1' && not != N)
		return (1);

	// test down
	xcell = ((PLY.x - (PLY.dx - CELL / 12)) / CELL);
	ycell = ((PLY.y	- (PLY.dy - CELL / 12)) / CELL);
	if (cub->map.data[ycell][xcell] == '1' && not != S)
		return (1);
	// test right
	if (!dx && !dy && not != E)
	{
		pa = PLY.pa + PI / 2;
		if (pa > (2 * PI))
			pa -= (2 * PI);
		dx = cos(pa);
		dy = sin(pa);
	}
	xcell = ((PLY.x + (dx + CELL / 12)) / CELL);
	ycell = ((PLY.y	+ (dy + CELL / 12)) / CELL);
	if (cub->map.data[ycell][xcell] == '1'  && not != E)
		return (1);
	// test left
	if (!dx && !dy && not != W)
	{
		pa = PLY.pa - PI / 2;
		if (pa < 0)
			pa += (2 * PI);
		dx = cos(pa);
		dy = sin(pa);
	}
	xcell = ((PLY.x + (dx - CELL / 12)) / CELL);
	ycell = ((PLY.y	+ (dy - CELL / 12)) / CELL);
	if (cub->map.data[ycell][xcell] == '1' && not != W)
		return (1);
	return (0);
}

void	move_up(t_cub *cub)
{
	// if (MAP.data[(PLY.x / CELL) - 1][PLY.y / CELL] == '0')
	if (!is_wall(cub, 0 , 0 , S))
	{
		PLY.x += PLY.dx;
		PLY.y += PLY.dy;
	}
}

void	move_down(t_cub *cub)
{
	// if (MAP.data[(PLY.x / CELL) + 1][PLY.y / CELL] == '0')

	if (!is_wall(cub, 0, 0, N))
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
	if (!is_wall(cub, dx ,dy, W))
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

	if (!is_wall(cub, dx, dy, E))
	{
		PLY.x += dx;
		PLY.y += dy;
	}
}
     
void	look_right(t_cub *cub)
{
	PLY.pa += 0.05;
	if (PLY.pa > (2 * PI))
		PLY.pa -= (2 * PI);
	PLY.dx += cos(PLY.pa);
	PLY.dy += sin(PLY.pa);
}

void	look_left(t_cub *cub)
{   
	PLY.pa -= 0.05;
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
