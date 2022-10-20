/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_player.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 19:43:55 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/19 20:46:32 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MANAGE_PLAYER_H
# define MANAGE_PLAYER_H

# include "../cub.h"
# include "../render_game/miniMap.h"

int	player_moves(int keycode, t_cub *cub);

#endif