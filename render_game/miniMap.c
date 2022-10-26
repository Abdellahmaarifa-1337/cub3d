/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:50:16 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/25 22:52:07 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./miniMap.h"

double	get_player_view_angle(t_cub *cub, int i, int j)
{
	if (MAP.data[i][j] == 'N')
		return ((3 * PI) / 2);
	if (MAP.data[i][j] == 'S')
		return (PI / 2);
	if (MAP.data[i][j] == 'E')
		return (0);
	else
		return (PI);
}

void	set_map_attribute(t_cub *cub)
{
	size_t	i;
	size_t	j;

	MAP.width = 0;
	MAP.height = 0;
	i = 0;
	while (MAP.data[i])
	{
		j = 0;
		while (MAP.data[i][j])
		{
			if (ft_strchr("NSWE", MAP.data[i][j]))
			{
				PLY.x = j * CELL + (float)((float)CELL / 2);
				PLY.y = i * CELL + (float)((float)CELL / 2);
				PLY.pa = get_player_view_angle(cub, i, j);
				MAP.data[i][j] = '0';
			}
			j++;
		}
		if (MAP.width < j)
			MAP.width = j;
		i++;
	}
	MAP.height = i;
}

void	putPlayer(t_cub *cub, float px, float py)
{
	int	x = 0;
	int	y = 0;

	y = - (CELL / 12);
	while (y < (CELL / 12))
	{
		x = - (CELL / 12);
		while (x < (CELL / 12))
		{
			my_mlx_pixel_put(cub, px + x, py + y, PLAYER);
			x++;
		}
		y++;
	}
}


int is_ray_up(t_cub *cub)
{
	if (PLY.pa > 0 && PLY.pa < PI)
		return (0);
	else if (PLY.pa > PI && PLY.pa < PI*2)
		return (1);
	return (2);
}


int is_out(t_cub *cub ,int x, int y)
{
	if (y / CELL < 0 || (size_t)y  >= MAP.height * CELL)
		return (1);
	if (x / CELL < 0 || (size_t)x >= ft_strlen(cub->map.data[y / CELL]) * CELL)
		return (1);
	// if (x / CELL < 0 || (size_t)x >= MAP.width * CELL)
	return (0);
}

int is_ray_right(t_cub *cub)
{
	if (PLY.pa > PI/2 && PLY.pa < 3 * PI/2)
		return (0);
	else if (PLY.pa < PI/2 || PLY.pa > 3 * PI/2)
		return (1);
	return (2);
}

int is_wall_ray(t_cub *cub, int x, int y)
{

	printf("om checck : x: %d y :%d\n", x/CELL, y/CELL);
	// printf("between : %d %d and %d %d\n",(y) / CELL,(x + 5)/ CELL,  (y + 5) / CELL, (x - 5) / CELL);
	if (MAP.data[(int)roundf(y / CELL)][(int)roundf(x / CELL)] == '1')
		return 1;
	if ( is_ray_up(cub) &&  !is_ray_right(cub) && MAP.data[(int)roundf((y) / CELL)][(int)roundf((x + 5) / CELL)] == '1' && MAP.data[(int)roundf((y + 5) / CELL)][(int)roundf((x - 5) / CELL)] == '1')
		return 1;
	if ( !is_ray_up(cub) &&  !is_ray_right(cub) && MAP.data[(int)roundf((y - 5) / CELL)][(int)roundf((x) / CELL)] == '1' && MAP.data[(int)roundf((y + 5) / CELL)][(int)roundf((x + 5) / CELL)] == '1')
		return 1;
	if ( !is_ray_up(cub) &&  is_ray_right(cub) && MAP.data[(int)roundf((y - 5) / CELL)][(int)roundf((x) / CELL)] == '1' && MAP.data[(int)roundf((y + 5) / CELL)][(int)roundf((x - 5) / CELL)] == '1')
		return 1;
	if ( is_ray_up(cub) &&  is_ray_right(cub) && MAP.data[(int)roundf((y - 5) / CELL)][(int)roundf((x - 5) / CELL)] == '1' && MAP.data[(int)roundf((y + 5) / CELL)][(int)roundf((x + 5) / CELL)] == '1')
	{
		// printf("between : %d %d and %d %d\n",(x - 5) / CELL * (y - 5)/ CELL, (x + 5) / CELL, (y + 5) / CELL);
		return 1;
	}
	return (0);
}
void get_ray_ver(t_cub *cub, int *ray)
{
	float fptx = 0;
	float fpty = 0;
	float ya = 0;
	float xa = 0;
	float px , py;
	float xas = 1;
	ray[0] = -1;
	ray[1] = -1;
	// get the first intersection
	if (is_ray_right(cub) == 1) 
	{
		printf("right\n");
		fptx = (int)(PLY.x / CELL) * CELL + CELL;
		xa = CELL;	
		//xas = -1;
	}
	else if (is_ray_right(cub) == 0)
	{
		printf("left\n");
		xa = -CELL;
		fptx = (int)(PLY.x / CELL) * CELL - 1 ;
		xas = -1;
	}
	else 
		return ;

	ya = (float)(xas * CELL) * (tan(PLY.pa));
	if (PLY.pa == 0 || PLY.pa == PI)
		fpty = PLY.y;
	else
		fpty = PLY.y + fabs((PLY.x - (float)fptx)) * tan(PLY.pa) * xas;
	
	// printf("size of the line : %zu\n", ft_strlen(cub->map.data[fpty / CELL]) * CELL);
	if (is_out(cub, fptx, fpty) )
	{
		ray[0] = -1;
		ray[1] = -1;	
		return ;
	}
	printf("p : %f %f\n", PLY.x , PLY.y );
	printf("%f %f\n",fptx / CELL , fpty / CELL);
	
	my_mlx_pixel_put(cub, (int)roundf(fptx ), (int)roundf(fpty), WALL);
	//return ;
	px = fptx ;
	py = fpty ;
	while (1)
	{
		// printf("p : %f %f\n", px / CELL, py / CELL);
		printf("max == %lu\n", cub->map.width * CELL);
		printf(".......... px: %f\tpy: %f\n", roundf(px / CELL), roundf(py / CELL));
		if (is_out(cub, roundf(px), roundf(py)))
		{
			ray[0] = -1;
			ray[1] = -1;
			printf("hohohohohohhohohohohohohohohhohohohohohohoho\n");
			break ;
		}
		printf("^^^^ver^^^^\n");
		if (is_wall_ray(cub, roundf(px), py))
		{
			ray[0] = px;
			ray[1] = py;
			putPlayer(cub, px, py);
			break ;
		}
		else
		{
			//printf("^^^^hor^^^^\n");
			putPlayer(cub, px, py);
			px += xa;
			py += ya;
			
		}
	}
	
	//my_mlx_pixel_put(cub, fptx + xa, fpty + ya, WALL);
	printf("max == %lu\n", cub->map.width * CELL);
	printf(">>>> %f %f -- %f, %f\n", PLY.x / CELL, PLY.y / CELL, fptx / CELL, fpty / CELL);
	(void)ray;
}

void get_ray(t_cub *cub, int *ray)
{
	float fptx = 0;
	float fpty = 0;
	float ya = 0;
	float xa = 0;
	float px , py;
	float xas = 1;
	// get the first intersection
	ray[0] = -1;
	ray[1] = -1;
	if (is_ray_up(cub) == 1) 
	{
		fpty = (int)(PLY.y / CELL) * CELL - 1;
		ya = -CELL;	
		xas = -1;
	}
	else if (is_ray_up(cub) == 0)
	{
		ya = +CELL;
		fpty = (int)(PLY.y / CELL) * CELL + CELL;
	}
	else 
	{
		return ;
	}
	xa = (float)(xas * CELL) / tan(PLY.pa);
	fptx = PLY.x + ((float)fpty - PLY.y)/tan(PLY.pa);
	
	// printf("size of the line : %zu\n", ft_strlen(cub->map.data[fpty / CELL]) * CELL);
	// if (is_out(cub, fptx, fpty))
	// return ;
	px = fptx ;
	py = fpty ;
	while (1)
	{
		// printf("p : %f %f\n", px / CELL, py / CELL);
		if (is_out(cub, px, py))
		{
			ray[0] = -1;
			ray[1] = -1;
			break ;
		}
		printf("^^^^hor^^^^\n");
		if (is_wall_ray(cub, px, py))
		{
			ray[0] = px;
			ray[1] = py;
			putPlayer(cub, px, py);
			break ;
		}
		else
		{
			putPlayer(cub, px, py);
			px += xa;
			py += ya;
			
		}
	}
	
	//my_mlx_pixel_put(cub, fptx + xa, fpty + ya, WALL);
	printf("max == %lu\n", cub->map.width * CELL);
	printf("%f %f -- %f, %f\n", PLY.x, PLY.y, fptx, fpty);
	(void)ray;
}

void	draw_line(t_cub *cub, float pa)
{
	int		pixels;
	float	dx;
	float	dy;
	float	px;
	float	py;
	int ray[2];
	int rayver[2];
	int smpx;
	// (void)pa;

	get_ray_ver(cub, rayver);
	get_ray(cub, ray);

	//float	drh = sqrt((pow(PLY.x - ray[0])));
	dx = cos(pa);
	dy = sin(pa);
	pixels = sqrt((ray[0] - PLY.x)*(ray[0] - PLY.x) + (ray[1] - PLY.y) * (ray[1] - PLY.y));
	int pix = sqrt((rayver[0] - PLY.x)*(rayver[0] - PLY.x) + (rayver[1] - PLY.y) * (rayver[1] - PLY.y));
	if (pix < pixels)
		smpx = pix;
	else
		smpx = pixels;
	if (ray[0] == rayver[0] && ray[1] == rayver[1])
	{
		smpx = pix;
		pixels = 0;
	}
	// if (ray[0] == -1 && ray[1] == -1)
	// {
	// 	smpx = pix;
	// 	pixels = 0;
	// }
	// if (rayver[0] == -1 && rayver[1] == -1)
	// {
	// 	smpx = pixels;
	// 	pix = 0;
	// }
	printf("ver: %d\thor: %d\n  +++++ %d ++++++\n", pix, pixels, smpx);
	// dx /= pixels;
	// dy /= pixels;

	px = PLY.x;
	py = PLY.y;
	while (smpx)
	{
		//printf("pa: %f\n", pa);
		// if (is_out(cub, px, py))
		// 	break;
		my_mlx_pixel_put(cub, px, py, LINE);
		px += dx;
		py += dy;
		--smpx;
	}
}

void	putPixels(t_cub *cub, size_t i[2], size_t axe[2], int unit)
{
	size_t	x;
	size_t	y;

	y = axe[1];
	while (y < (i[0] + 1) * CELL - 1)
	{
		x = axe[0];
		while (x < (i[1] + 1) * CELL - 1)
		{
			if (unit)
				my_mlx_pixel_put(cub, x, y, WALL);
			else
				my_mlx_pixel_put(cub, x, y, EMPTY);
			x++;
		}
		y++;
	}
}

void	renderingTheMap(t_cub* cub)
{
	size_t	i[2];
	size_t	axe[2];

	i[0] = 0;
	axe[1] = 0;
	while (MAP.data[i[0]])
	{
		i[1] = 0;
		axe[0] = 0;
		while (MAP.data[i[0]][i[1]]) {
			if (MAP.data[i[0]][i[1]] == '1')
				putPixels(cub, i, axe, 1);
			else if (MAP.data[i[0]][i[1]] == '0'
				|| ft_strchr("NSWE", MAP.data[i[0]][i[1]]))
				putPixels(cub, i, axe, 0);
			i[1]++;
			axe[0] += CELL;
		}
		i[0]++;
		axe[1] += CELL;
	}
}

void	my_mlx_clear_image(t_cub *cub)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < MAP.height * CELL) {
		j = 0;
		while (j < MAP.width * CELL) {
			my_mlx_pixel_put(cub, j, i, 0x0);
			j++;
		}
		i++;
	}
}

int	execute_MiniMap(t_cub* cub)
{

	PLY.dx = cos(PLY.pa) * 5;
	PLY.dy = sin(PLY.pa) * 5;
	my_mlx_clear_image(cub);
	mlx_clear_window(cub->mlx, cub->mlx_win);
	renderingTheMap(cub);
	putPlayer(cub, PLY.x, PLY.y);
	draw_line(cub, PLY.pa);
	// 	draw_line(cub, PLY.pa + (PI / 12));
	// 	draw_line(cub, PLY.pa - (PI / 12));
	// 	draw_line(cub, PLY.pa + (PI / 6));
	// 	draw_line(cub, PLY.pa - (PI / 6));
	
	// int	pa;
	// pa = PLY.pa;
	// while (pa >= PLY.pa - (PI / 6))
	// {
	// 	draw_line(cub, pa);
	// 	pa += 0.1;
	// }
	// pa = PLY.pa + 0.1;
	// while (pa <= PLY.pa + (PI / 6))
	// {
	// 	draw_line(cub, pa);
	// 	pa -= 0.1;
	// }
	
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, IMG.img, 0, 0);
	return (0);
}

