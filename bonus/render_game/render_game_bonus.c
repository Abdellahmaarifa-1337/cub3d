/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/19 10:50:50 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"
#include "render_game_bonus.h"
#include "../manage_player/manage_player_bonus.h"

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

void	init_miniMap(t_cub *cub)
{
	cub->m_map.img = mlx_new_image(cub->mlx, 7 * 40, 5 * 40);
	cub->m_map.addr = mlx_get_data_addr(cub->m_map.img, &cub->m_map.bits_per_pixel, &cub->m_map.line_length,
		&cub->m_map.endian);
}

int	render_frames(t_cub *cub)
{
	if (cub->keys[0] == 1 || cub->keys[1] == 1 || cub->keys[2] == 1 ||
		cub->keys[3] == 1 || cub->keys[4] == 1 || cub->keys[5] == 1)
	{
		player_moves(cub);
		render_scene(cub);
		execute_minimap(cub);
	}
	return (0);
}

void	render_game(t_cub *cub)
{
	int	d;

	init_mlx(cub);
	init_miniMap(cub);
	init_textures(cub, &d);
	initializing_keys(cub);
	render_scene(cub);
	execute_minimap(cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, pressed_keys, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, released_keys, cub);
	mlx_loop_hook(cub->mlx, render_frames, cub);
	cub->mouse_on = 0;
	mlx_hook(cub->mlx_win, 6, 0L, &mouse_hook, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);
	mlx_loop(cub->mlx);
}
