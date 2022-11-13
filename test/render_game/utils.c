/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:27:53 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/12 21:34:19 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"render_game.h"

float	get_player_view_angle(t_cub *cub, int i, int j)
{
	if (cub->map.data[i][j] == 'N')
		return ((3 * PI) / 2);
	if (cub->map.data[i][j] == 'S')
		return (PI / 2);
	if (cub->map.data[i][j] == 'E')
		return (0);
	else
		return (PI);
}

void	set_map_attribute(t_cub *cub)
{
	size_t	i;
	size_t	j;

	cub->map.width = 0;
	cub->map.height = 0;
	i = 0;
	while (cub->map.data[i])
	{
		j = 0;
		while (cub->map.data[i][j])
		{
			if (ft_strchr("NSWE", cub->map.data[i][j]))
			{
				cub->p.x = j * CELL + (float)((float)CELL / 2);
				cub->p.y = i * CELL + (float)((float)CELL / 2);
				cub->p.pa = get_player_view_angle(cub, i, j);
				cub->map.data[i][j] = '0';
			}
			j++;
		}
		if (cub->map.width < j)
			cub->map.width = j;
		i++;
	}
	cub->map.height = i;
}

void	my_mlx_clear_image(t_img *img, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			my_mlx_pixel_put(img, j, i, 0x0);
			j++;
		}
		i++;
	}
}
