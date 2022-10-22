/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:50 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/22 12:30:26 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	_my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }


int	main(int ac, char **av)
{

	t_cub	g;

	if (ac != 2)
		throw_error("Error : invalid argmuents!", 1);
	g.idn._no = NULL;
	*(g.idn._c) = -1;
	g.idn._ea = NULL;
	*(g.idn._f) = -1;
	g.idn._so = NULL;
	g.idn._we = NULL;
	g.map.height = 0;
	g.map.width = 0;
	g.map.data = (char **)(malloc(sizeof(char *) * 2));
	g.map.map_size = 0;
	g.map.map_capacity = 1;
	g.map.height = 0;
	g.map.width = 0;
	g.map.player = 0;
	g.map.data[g.map.map_capacity] = NULL;
	parse_map(av[1], &g);
	set_map_attribute(&g);
	render_game(&g);

	// void *mlx;
	// void *mlx_win;
	// t_data	img;
	// int i, j;
	
	// mlx = mlx_init();
	// img.img = mlx_new_image(mlx, 300, 300);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);
	// i = 0;
	// while (i < 300)
	// {
	// 	j = 0;
	// 	while(j < 300)
	// 	{
	// 		_my_mlx_pixel_put(&img, i, j, 0x00FF0000);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// mlx_win = mlx_new_window(mlx, 300, 300, "Hello world!");
	// mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	// mlx_loop(mlx);
	
	return (0);
}
