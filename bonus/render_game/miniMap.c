/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/11/17 14:58:24 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./render_game.h"

// float	get_player_view_angle(t_cub *cub, int i, int j)
// {
// 	if (cub->map.data[i][j] == 'N')
// 		return ((3 * PI) / 2);
// 	if (cub->map.data[i][j] == 'S')
// 		return (PI / 2);
// 	if (cub->map.data[i][j] == 'E')
// 		return (0);
// 	else
// 		return (PI);
// }

// void	set_map_attribute(t_cub *cub)
// {
// 	size_t	i;
// 	size_t	j;

// 	cub->map.width = 0;
// 	cub->map.height = 0;
// 	i = 0;
// 	while (cub->map.data[i])
// 	{
// 		j = 0;
// 		while (cub->map.data[i][j])
// 		{
// 			if (ft_strchr("NSWE", cub->map.data[i][j]))
// 			{
// 				cub->p.x = j * CELL + (float)(CELL / 2);
// 				cub->p.y = i * CELL + (float)(CELL / 2);
// 				cub->p.pa = get_player_view_angle(cub, i, j);
// 				cub->map.data[i][j] = '0';
// 			}
// 			j++;
// 		}
// 		if (cub->map.width < j)
// 			cub->map.width = j;
// 		i++;
// 	}
// 	cub->map.height = i;
// }

void direction_ray(t_cub *cub, float px, float py)
{
	float	dx;
	float	dy;
	int		pixels;

	dx = cos(cub->p.pa);
	dy = sin(cub->p.pa);
	pixels = 0;
	while (pixels < 25)
	{
		my_mlx_pixel_put(&(cub->minimap), px, py, 0x00000032);
		px += dx;
		py += dy;
		pixels++;
	}
}
void	putPlayer(t_cub *cub)
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
			my_mlx_pixel_put(&(cub->minimap), (int)x, (int)y, PLAYER);
			x++;
		}
		y++;
	}
	direction_ray(cub, px, py);
}

float get_dist(t_cub *cub, float x, float y)
{
	return (sqrt((x - cub->p.x)*(x - cub->p.x) + (y - cub->p.y) * (y - cub->p.y)));
}

// void	my_mlx_clear_image(t_img *img, int height, int width)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < height) {
// 		j = 0;
// 		while (j < width) {
// 			my_mlx_pixel_put(img, j, i, 0x0);
// 			j++;
// 		}
// 		i++;
// 	}
// }

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
	else if (begin[1] > (float)(cub->map.height * 40.0f) - (float)(5.0f * 40.0f))
	{
		begin[1] = (float)(cub->map.height * 40.0f) - (float)(5.0f * 40.0f);
		end[1] = (float)cub->map.height * 40.0f;
	}
	cub->begin[0] = begin[0];
	cub->begin[1] = begin[1];
	cub->end[0] = end[0];
	cub->end[1] = end[1];
}

void	putPixels(t_cub *cub, float begin[2], int x_end, int px_line)
{
	int	x;
	int	x_begin;

	x = 0;
	x_begin = begin[0];
	while (x_begin < x_end && cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)])
	{
		if (cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)] == '1')
			my_mlx_pixel_put(&(cub->minimap), x, px_line, 0x00000032);
		else if (cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)] == '0'
			|| ft_strchr("NSWE", cub->map.data[(int)(begin[1] / 40.0f)][(int)(x_begin / 40.0f)]))
			my_mlx_pixel_put(&(cub->minimap), x, px_line, 0x49494932);
		else
			my_mlx_pixel_put(&(cub->minimap), x, px_line, 0xFFFFFF00);
		x_begin++;
		x++;
	}
	while (x < (float)(7 * 40.0f))
	{
		my_mlx_pixel_put(&(cub->minimap), x, px_line, 0xFFFFFF00);
		x++;
	}
}

void	renderingTheMap(t_cub* cub)
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
		putPixels(cub, begin, end[0], px_line);
		begin[1] += 1;
		px_line++;
	}
	putPlayer(cub);
}

int	execute_minimap(t_cub* cub)
{
	cub->p.dx = cos(cub->p.pa) * 5;
	cub->p.dy = sin(cub->p.pa) * 5;
	my_mlx_clear_image(&(cub->minimap), 5 * 40, 7 * 40);
	renderingTheMap(cub);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->minimap.img, 0, 0);
	return (0);
}
