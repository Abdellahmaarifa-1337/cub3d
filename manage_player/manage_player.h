/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:55 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/28 16:39:51 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MANAGE_PLAYER_H
# define MANAGE_PLAYER_H

# include "../cub.h"
# include "../render_game/miniMap.h"

/***************** MOUSE HOOK ******************/
int		mouse_hook(int x, int y, t_cub *cub);
int		mouse_switcher(int button, int x, int y, t_cub *cub);

/********** PLAYER MOVES MANAGEMENT ************/
int		pressed_keys(int keycode, t_cub *cub);
int		released_keys(int keycode, t_cub *cub);
void	player_moves(t_cub *cub);
int		is_wall(t_cub *cub, int x, int y);

/************** PLAYER MOVEMENTS **************/
void	move_up(t_cub *cub);
void	move_down(t_cub *cub);
void	move_right(t_cub *cub);
void	move_left(t_cub *cub);

/*************** PLAYER EYESIGHT **************/
void	look_right(t_cub *cub);
void	look_left(t_cub *cub);

#endif