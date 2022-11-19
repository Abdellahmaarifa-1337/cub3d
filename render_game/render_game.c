/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/19 12:15:14 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
#include "render_game.h"
#include "../manage_player/manage_player.h"

int	ft_close(void)
{
	exit(0);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(int *)dst = color;
}

int	render_frames(t_cub *cub)
{
	if (cub->keys[0] == 1 || cub->keys[1] == 1 || cub->keys[2] == 1
		|| cub->keys[3] == 1 || cub->keys[4] == 1 || cub->keys[5] == 1)
	{
		player_moves(cub);
		render_scene(cub);
	}
	return (0);
}

void	render_game(t_cub *cub)
{
	int	d;

	init_mlx(cub);
	init_textures(cub, &d);
	initializing_keys(cub);
	render_scene(cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, pressed_keys, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, released_keys, cub);
	mlx_loop_hook(cub->mlx, render_frames, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);
	mlx_loop(cub->mlx);
}
