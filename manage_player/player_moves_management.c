/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves_management.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:26:12 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/17 16:29:38 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_player.h"

int	is_wall(t_cub *cub, float dx, float dy)
{
	if ( cub->map.data[(int)((cub->p.y + dy) / CELL)][(int)((cub->p.x + dx) / CELL)] == '1'
		|| (cub->map.data[(int)(cub->p.y / CELL)][(int)((cub->p.x + dx) / CELL)] == '1'
		&& cub->map.data[(int)((cub->p.y + dy) / CELL)][(int)(cub->p.x / CELL)] == '1'))
		return (1);
	if (dx < 0)
		dx += 2;
	else
		dx -= 2;
	if (dy < 0)
		dy += 2;
	else
		dy -= 2;
	if ( cub->map.data[(int)((cub->p.y + dy) / CELL)][(int)((cub->p.x + dx) / CELL)] == '1'
		|| (cub->map.data[(int)(cub->p.y / CELL)][(int)((cub->p.x + dx) / CELL)] == '1'
		&& cub->map.data[(int)((cub->p.y + dy) / CELL)][(int)(cub->p.x / CELL)] == '1'))
	 	return (1);
	// if (cub->map.data[(int)((cub->p.y + dy + 1) / CELL)]
	// 	[(int)((cub->p.x + dx) / CELL)] == '1'
	// 	|| cub->map.data[(int)((cub->p.y + dy - 1) / CELL)]
	// 	[(int)((cub->p.x + dx) / CELL)] == '1'
	// 	|| cub->map.data[(int)((cub->p.y + dy) / CELL)]
	// 	[(int)((cub->p.x + dx + 1) / CELL)] == '1'
	// 	|| cub->map.data[(int)((cub->p.y + dy) / CELL)]
	// 	[(int)((cub->p.x + dx - 1) / CELL)] == '1'
	// 	|| cub->map.data[(int)((cub->p.y + dy + 1) / CELL)]
	// 	[(int)((cub->p.x + dx + 1) / CELL)] == '1')
	// 	return (1);
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
	{
		player_moves(cub);
		render_scene(cub);
	}
	return (0);
}

void	player_angle(int keycode, t_cub *cub)
{
	if (keycode == 69)
		cub->p.inc_pa += 0.01;
	if (keycode == 78)
		cub->p.inc_pa -= 0.01;
	if (cub->p.inc_pa <= 0)
		cub->p.inc_pa = 0.01;
	else if (cub->p.inc_pa > 0.1)
		cub->p.inc_pa = 0.1;
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
	return (0);
}
