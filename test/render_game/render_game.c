/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 08:58:40 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/13 21:45:17 by amaarifa         ###   ########.fr       */
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
	*(unsigned int *)dst = color;
}

void	render_game(t_cub *cub)
{
	int	d;

	init_mlx(cub);
	init_textures(cub, &d);
	initializing_keys(cub);
	mlx_loop_hook(cub->mlx, render_scene, cub);
	mlx_hook(cub->mlx_win, 2, 1L << 0, pressed_keys, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, released_keys, cub);
	mlx_hook(cub->mlx_win, 17, 1L << 5, ft_close, cub);
	mlx_loop(cub->mlx);
}
