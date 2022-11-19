/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/19 11:09:37 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_game_bonus.h"

void	direction_ray(t_cub *cub, float px, float py)
{
	float	dx;
	float	dy;
	int		pixels;

	dx = cos(cub->p.pa);
	dy = sin(cub->p.pa);
	pixels = 0;
	while (pixels < 25)
	{
		my_mlx_pixel_put(&(cub->m_map), px, py, 0x00000032);
		px += dx;
		py += dy;
		pixels++;
	}
}

void	put_player(t_cub *cub)
{
	float	x;
	float	y;
	float	px;
	float	py;

	x = 7.0f * 40.0f - cub->end[0] + (cub->p.x / (float)CELL) * 40.0f;
	y = 5.0f * 40.0f - cub->end[1] + (cub->p.y / (float)CELL) * 40.0f;
	px = x;
	py = y;
	y -= 2;
	while (y < py + 2)
	{
		x = px - 2;
		while (x < px + 2)
		{
			my_mlx_pixel_put(&(cub->m_map) , (int)x, (int)y, PLAYER);
			x++;
		}
		y++;
	}
	direction_ray(cub, px, py);
}

void	init(t_cub *cub, float begin[2], float end[2])
{
	begin[1] = (cub->p.y / (float)CELL) * 40.0f - 2.5f * 40.0f;
	begin[0] = (cub->p.x / (float)CELL) * 40.0f - 3.5f * 40.0f;
	end[1] = (cub->p.y / (float)CELL) * 40.0f + 2.5f * 40.0f;
	end[0] = (cub->p.x / (float)CELL) * 40.0f + 3.5f * 40.0f;
	if (begin[0] < 0)
	{
		begin[0] = 0;
		end[0] = 7.0f * 40.0f;
	}
	else if (begin[0] > (float)(cub->map.width * 40.0f) - (float)(7.0f * 40.0f))
	{
		begin[0] = (float)(cub->map.width * 40.0f) - (float)(7.0f * 40.0f);
		end[0] = (float)cub->map.width * 40.0f;
	}
	if (begin[1] < 0)
	{
		begin[1] = 0;
		end[1] = 5.0f * 40.0f;
	}
	else if (begin[1] > (float)(cub->map.height * 40.0f)
		- (float)(5.0f * 40.0f))
	{
		begin[1] = (float)(cub->map.height * 40.0f) - (float)(5.0f * 40.0f);
		end[1] = (float)cub->map.height * 40.0f;
	}
	cub->begin[0] = begin[0];
	cub->begin[1] = begin[1];
	cub->end[0] = end[0];
	cub->end[1] = end[1];
}

void	rendering_the_map(t_cub *cub)
{
	float	begin[2];
	float	end[2];
	int		px_line;
	int		x;

	init(cub, begin, end);
	px_line = 0;
	while (cub->map.data[(int)(begin[1] / 40)] && begin[1] < end[1])
	{
		x = begin[0];
		put_pixels(cub, begin, px_line);
		begin[1] += 1;
		px_line++;
	}
	put_player(cub);
}

int	execute_minimap(t_cub *cub)
{
	cub->p.dx = cos(cub->p.pa) * 2;
	cub->p.dy = sin(cub->p.pa) * 2;
	my_mlx_clear_image(&(cub->m_map), 5 * 40, 7 * 40);
	rendering_the_map(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->m_map.img, 0, 0);
	return (0);
}
