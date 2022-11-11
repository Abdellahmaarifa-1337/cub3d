/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:26:12 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/08 15:17:59 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_player.h"

int is_wall(t_cub *cub, float dx, float dy)
{
	if (dx < 0)
		dx -= 2;
	else
		dx += 2;
	if (dy < 0)
		dy -= 2;
	else
		dy += 2;
	if (MAP.data[(int)((PLY.y + dy) / CELL)][(int)((PLY.x + dx) / CELL)] == '1'
		|| (MAP.data[(int)(PLY.y / CELL)][(int)((PLY.x + dx) / CELL)] == '1'
		&& MAP.data[(int)((PLY.y + dy) / CELL)][(int)(PLY.x / CELL)] == '1'))
		return (1);
	return (0);
}

void	player_moves(t_cub *cub)
{
	if (cub->keys[0] && !cub->keys[1])
		move_up(cub);
	if (cub->keys[1] && !cub->keys[0])
		move_down(cub);
	if (cub->keys[2] && !cub->keys[3])
		move_right(cub);
	if (cub->keys[3] && !cub->keys[2])
		move_left(cub);
	if (cub->keys[4] && !cub->keys[5])
		look_right(cub);
	if (cub->keys[5] && !cub->keys[4])
		look_left(cub);
}

int	pressed_keys(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->keys[0] = 1;
	if (keycode == 1)
		cub->keys[1] = 1;
	if (keycode == 2)
		cub->keys[2] = 1;
	if (keycode == 0)
		cub->keys[3] = 1;
	if (keycode == 124)
		cub->keys[4] = 1;
	if (keycode == 123)
		cub->keys[5] = 1;
	if (keycode == 53)
		exit(0);
	else
		player_moves(cub);
		return (0);
}

void	player_angle(int keycode, t_cub *cub)
{
	if (keycode == 69)
		PLY.inc_pa += 0.01;
	if (keycode == 78)
		PLY.inc_pa -= 0.01;
	if (PLY.inc_pa <= 0)
		PLY.inc_pa = 0.01;
	else if (PLY.inc_pa > 0.1)
		PLY.inc_pa = 0.1;
}

int	released_keys(int keycode, t_cub *cub)
{
	if (keycode == 13)
		cub->keys[0] = 0;
	if (keycode == 1)
		cub->keys[1] = 0;
	if (keycode == 2)
		cub->keys[2] = 0;
	if (keycode == 0)
		cub->keys[3] = 0;
	if (keycode == 124)
		cub->keys[4] = 0;
	if (keycode == 123)
		cub->keys[5] = 0;
	if (keycode == 69 || keycode == 78)
		player_angle(keycode, cub);
	if (keycode == 259 || keycode == 260)
		mouse_switcher(cub);
		return (0);
}
