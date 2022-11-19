/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_eyesight.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:39:51 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/18 16:30:09 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manage_player.h"

void	look_right(t_cub *cub)
{
	cub->p.pa += cub->p.inc_pa;
	if (cub->p.pa > (2 * PI))
		cub->p.pa -= (2 * PI);
	cub->p.dx += cos(cub->p.pa) * 2;
	cub->p.dy += sin(cub->p.pa) * 2;
}

void	look_left(t_cub *cub)
{
	cub->p.pa -= cub->p.inc_pa;
	if (cub->p.pa < 0)
		cub->p.pa += (2 * PI);
	cub->p.dx += cos(cub->p.pa) * 2;
	cub->p.dy += sin(cub->p.pa) * 2;
}
