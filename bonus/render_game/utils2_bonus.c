/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:53:29 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/19 11:09:08 by mkabissi         ###   ########.fr       */
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
