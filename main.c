/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:50 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 08:35:27 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


// int get_color(t_data *img, int x, int y)
// {
// 	char *index = img->addr + (img->line_length * y + x * (img->bits_per_pixel / 8));
// 	printf("%d\n", *(int *)index);
// 	return (*(int *)index);
// };


// void test()
// {
// 	t_data img;
// 	int y[2];
// 	int y1;
// 	void *mlx = mlx_init();
// 	void *mlx_win = mlx_new_window(mlx, 1080, 1920, "img");
// 	img.img = mlx_xpm_file_to_image(mlx, "./test/GON.xpm", y, y);
// 	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
// 	//printf("%d\n %d \n", *((int *)img.addr), img.line_length);
// 	for(int j = 0; j < 320; j++)
// 	{
// 		for(int i = 0; i < 460; i++)
// 		{
// 			mlx_pixel_put(mlx, mlx_win, i, j, get_color(&img, i, j));
// 		}
// 	}
// 	//mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
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
	g.p.inc_pa = INC_PA;
	parse_map(av[1], &g);
	set_map_attribute(&g);
	render_game(&g);

	//test();
	return (0);
}
