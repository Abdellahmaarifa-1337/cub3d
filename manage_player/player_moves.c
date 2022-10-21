/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/21 05:45:11 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"
#include <math.h>

void	move_up(t_cub *cub)
{
	// if (MAP.data[(PLY.x / CELL) - 1][PLY.y / CELL] == '0')
		PLY.x += PLY.dx;
		PLY.y += PLY.dy;
}

void	move_down(t_cub *cub)
{
	// if (MAP.data[(PLY.x / CELL) + 1][PLY.y / CELL] == '0')
		PLY.x -= PLY.dx;
		PLY.y -= PLY.dy;
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
	PLY.x += dx;
	PLY.y += dy;
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
	PLY.x += dx;
	PLY.y += dy;
}
     
void	look_right(t_cub *cub)
{
	PLY.pa += 0.1;
	if (PLY.pa > (2 * PI))
		PLY.pa -= (2 * PI);
	PLY.dx += cos(PLY.pa) * 5; 
	PLY.dy += sin(PLY.pa) * 5;
}

void	look_left(t_cub *cub)
{   
	PLY.pa -= 0.1;
	if (PLY.pa < 0)
		PLY.pa += (2 * PI);
	PLY.dx += cos(PLY.pa) * 5;
	PLY.dy += sin(PLY.pa) * 5;
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
