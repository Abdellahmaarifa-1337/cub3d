/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:42:32 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/17 14:46:53 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_game.h"

void	*get_image(t_cub *cub, char *img_path, int *d)
{
	void	*img;

	img = mlx_xpm_file_to_image(cub->mlx, img_path, d, d);
	if (!img)
	{
		ft_putstr_fd(img_path, 2);
		ft_putendl_fd(" : Invalide file", 2);
		exit(1);
	}
	return (img);
}

void	init_textures(t_cub *cub, int *d)
{
	cub->textures[0].img = get_image(cub, cub->idn._no, d);
	cub->textures[0].addr = mlx_get_data_addr(cub->textures[0].img,
			&(cub->textures[0].bits_per_pixel),
			&(cub->textures[0].line_length), &(cub->textures[0].endian));
	cub->textures[1].img = get_image(cub, cub->idn._so, d);
	cub->textures[1].addr = mlx_get_data_addr(cub->textures[1].img,
			&(cub->textures[1].bits_per_pixel),
			&(cub->textures[1].line_length), &(cub->textures[1].endian));
	cub->textures[2].img = get_image(cub, cub->idn._ea, d);
	cub->textures[2].addr = mlx_get_data_addr(cub->textures[2].img,
			&(cub->textures[2].bits_per_pixel),
			&(cub->textures[2].line_length), &(cub->textures[2].endian));
	cub->textures[3].img = get_image(cub, cub->idn._we, d);
	cub->textures[3].addr = mlx_get_data_addr(cub->textures[3].img,
			&(cub->textures[3].bits_per_pixel),
			&(cub->textures[3].line_length), &(cub->textures[3].endian));
}

void	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	cub->mlx_win = mlx_new_window(cub->mlx, WIN_WIDHT,
			WIN_HEIGHT, "miniMap");
	cub->img.img = mlx_new_image(cub->mlx, WIN_WIDHT, WIN_HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
}

void	initializing_keys(t_cub *cub)
{
	cub->keys[0] = 0;
	cub->keys[1] = 0;
	cub->keys[2] = 0;
	cub->keys[3] = 0;
	cub->keys[4] = 0;
	cub->keys[5] = 0;
	cub->mouse_on = 0;
	cub->prev_x_mouse = WIN_WIDHT / 2;
}
