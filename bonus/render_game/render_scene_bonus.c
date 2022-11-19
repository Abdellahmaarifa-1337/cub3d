/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_scene_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:21:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/18 19:20:48 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_game_bonus.h"

#define DPP 255

void	draw_sky(t_cub *cub, int x, int end)
{
	int	y;

	y = 0;
	while (y < end)
	{
		my_mlx_pixel_put(&(cub->img), x, y,
			rgb_to_int(cub->idn._c[0], cub->idn._c[1], cub->idn._c[2]));
		y++;
	}
}

void	draw_floor(t_cub *cub, int i, int end)
{
	while (end < WIN_HEIGHT)
	{
		my_mlx_pixel_put(&(cub->img), i, end,
			rgb_to_int(cub->idn._f[0], cub->idn._f[1], cub->idn._f[2]));
		end++;
	}
}

void	draw_slice(t_cub *cub, int psh, int i)
{
	int		index;
	int		end;
	double	size;
	int		start;
	int		reminder;

	reminder = 0;
	if (psh > WIN_HEIGHT)
	{
		reminder = (psh - WIN_HEIGHT) / 2;
		psh = WIN_HEIGHT;
	}
	index = WIN_HEIGHT / 2 - psh / 2;
	draw_sky(cub, i, index);
	end = index + psh;
	start = index;
	while (index < end && index < WIN_HEIGHT)
	{
		size = (double)(index - start) / psh;
		if (psh + reminder * 2 > WIN_HEIGHT)
			size = (double)(index - start + reminder) / (psh + (reminder * 2));
		my_mlx_pixel_put(&(cub->img), i, index,
			get_color_from_texture(cub, size));
		index++;
	}
	draw_floor(cub, i, end);
}

int	render_scene(t_cub *cub)
{
	double		dp;
	double		an;
	double		dist;
	int			i;

	my_mlx_clear_image(&(cub->img), WIN_HEIGHT, WIN_WIDHT);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	cub->p.dx = cos(cub->p.pa) * 2;
	cub->p.dy = sin(cub->p.pa) * 2;
	i = 0;
	dp = (float)(PI / (3.0 * (float)WIN_WIDHT));
	an = cub->p.pa - PI / 6;
	while (an < cub->p.pa + PI / 6 && i < WIN_WIDHT)
	{
		cub->map.ray_pa = an;
		dist = get_ray_dist(cub);
		draw_slice(cub, ((float)(CELL * 3) / dist) * (float)DPP, i);
		an += dp;
		i++;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->img.img, 0, 0);
	return (0);
}
