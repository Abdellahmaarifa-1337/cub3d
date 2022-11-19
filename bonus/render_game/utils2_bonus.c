/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:53:29 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/19 12:03:44 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"render_game_bonus.h"

float	get_dist(t_cub *cub, float x, float y)
{
	return (sqrt((x - cub->p.x) * (x - cub->p.x)
			+ (y - cub->p.y) * (y - cub->p.y)));
}

void	put_pixels(t_cub *cub, float begin[2], int px_line)
{
	int	x;
	int	x_begin;

	x = 0;
	x_begin = begin[0];
	while (cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)])
	{
		if (cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)]
			== '1')
			my_mlx_pixel_put(&(cub->m_map), x, px_line, 0x00000032);
		else if (cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)]
			== '0'
			|| ft_strchr("NSWE", cub->map.data[(int)(begin[1] / 40.0f)]
				[(int)(x_begin / 40.0f)]))
			my_mlx_pixel_put(&(cub->m_map), x, px_line, 0x49494932);
		else
			my_mlx_pixel_put(&(cub->m_map), x, px_line, 0xFFFFFF00);
		x_begin++;
		x++;
	}
	while (x < (float)(7 * 40.0f))
	{
		my_mlx_pixel_put(&(cub->m_map), x, px_line, 0xFFFFFF00);
		x++;
	}
}

void	protect_edges(t_cub *cub, float begin[2], float end[0])
{
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
}

void	init(t_cub *cub, float begin[2], float end[2])
{
	begin[1] = (cub->p.y / (float)CELL) * 40.0f - 2.5f * 40.0f;
	begin[0] = (cub->p.x / (float)CELL) * 40.0f - 3.5f * 40.0f;
	end[1] = (cub->p.y / (float)CELL) * 40.0f + 2.5f * 40.0f;
	end[0] = (cub->p.x / (float)CELL) * 40.0f + 3.5f * 40.0f;
	protect_edges(cub, begin, end);
	cub->begin[0] = begin[0];
	cub->begin[1] = begin[1];
	cub->end[0] = end[0];
	cub->end[1] = end[1];
}
