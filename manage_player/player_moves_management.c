/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:26:12 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/26 22:30:06 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_player.h"

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
		return (0);
}
