/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_eyesight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:39:51 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/29 23:34:03 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_player.h"

void	look_right(t_cub *cub)
{
	PLY.pa += PLY.inc_pa;
	if (PLY.pa > (2 * PI))
		PLY.pa -= (2 * PI);
	PLY.dx += cos(PLY.pa) * 2;
	PLY.dy += sin(PLY.pa) * 2;
}

void	look_left(t_cub *cub)
{
	PLY.pa -= PLY.inc_pa;
	if (PLY.pa < 0)
		PLY.pa += (2 * PI);
	PLY.dx += cos(PLY.pa) * 2;
	PLY.dy += sin(PLY.pa) * 2;
}
