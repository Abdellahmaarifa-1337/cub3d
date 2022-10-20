/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 23:23:04 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/20 11:21:30 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./manage_player.h"
#include <math.h>

void	move_up(t_cub *cub)
{
	// if (MAP.data[(PLY.x / CELL) - 1][PLY.y / CELL] == '0')
		PLY.y = roundf(PLY.y - 5);
}

void	move_down(t_cub *cub)
{
	// if (MAP.data[(PLY.x / CELL) + 1][PLY.y / CELL] == '0')
		PLY.y = roundf(PLY.y + 5);
}

void	move_right(t_cub *cub)
{
	// if (MAP.data[PLY.x / CELL][(PLY.y / CELL) + 1] == '0')
		PLY.x = roundf(PLY.x + 5);
}

void	move_left(t_cub *cub)
{
	// if (MAP.data[PLY.x][PLY.y - 1] == '0')
		PLY.x = roundf(PLY.x - 5);
}

int	player_moves(int keycode, t_cub *cub)
{
	(void)cub;
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0 \
	|| keycode == 124 || keycode == 123)
	{
		if (keycode == 13/* || keycode == 126*/)
			move_up(cub);
		if (keycode == 1 /*|| keycode == 125*/)
			move_down(cub);
		if (keycode == 2 /*|| keycode == 124*/)
			move_right(cub);
		if (keycode == 0 /*|| keycode == 123*/)
			move_left(cub);
	}
	if (keycode == 53)
		exit(0);
	return (0);
}
