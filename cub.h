/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/02 12:35:59 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
#include "./mlx/mlx.h"
#include "limits.h"

# define	MAP	cub->map
# define	PLY cub->p
# define	RAY cub->ray
# define	IMG	cub->img

// GAME VARIBALES

# define EXT_LEN	4
# define EXT	".cub"
# define IDENTIFIERS_NUMBER	6
# define N	1
# define S	2
# define E	3
# define W	4

# define WIN_WIDHT	1080
# define WIN_HEIGHT	720
# define CELL		32
# define PLY_WIDTH	CELL/6
# define PI			3.14159265359
# define INC_PA		0.02

// COLORS

# define PRUPLE		0xFB2576
# define EMPTY		0x494949
# define WALL		0xE1E6E6
# define PLAYER		0xF5DC50
# define LINE		0xFF7D2D



typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_idn
{
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
	int		_f[3];
	int		_c[3];
}	t_idn;

typedef struct s_map
{
	char	**data;
	size_t	width;
	size_t	height;
	int		map_capacity;
	int		map_size;
	int		player;
	float	ray_pa;
}	t_map;

typedef	struct s_ray
{
	float	rayLenght;
}	t_ray;


typedef struct s_player
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	pa;
	float	inc_pa;
}	t_player;

typedef struct s_rays
{
	/* data */
	double	pa;
	int		x;
	int		y;
	double	ray_dist;
	int		is;
} t_rays;

typedef struct s_intersection
{
	/* data */
	int is_ver;
	int inter_h;
	int inter_v;
	int inter;
} t_intersection;

// Gloabl struct
typedef struct s_cub
{
	t_map		map;
	t_idn		idn;
	t_player	p;
	t_ray		ray;
	t_img		img;
	t_rays		rays[WIN_WIDHT + 1];
	void*		mlx;
	void*		mlx_win;
	void*		mlx3d;
	void*		mlx3d_win;
	t_img		img3d;
	int			keys[6];
	int			mouse_on;
	int			prev_x_mouse;
	t_img		textuers;
	t_intersection	inter;
}	t_cub;

int		parse_map(const char *path, t_cub *g);
void	throw_error(const char *error, int _ex);
void	render_game(t_cub *cub);
void	get_identifiers(int fd, t_idn *idn);
void	get_map(int fd, t_cub *g);
// utils
void	realloc_map(t_map *map);
void	push_back(t_map *map, char *line);
int		get_char(char *s, int c);
int		is_full_space(char *tmp);

// get map utils
void	check_allowed_char(char *s);
void	get_player(t_map *map, char *line);
void	check_walls(char *line);
char	*get_first_line(int fd);
void	check_player(int player);
void	check_if_close(t_map *map, size_t i, size_t j);

// get idn utils
void	free_line(char **line);
int		calc_line_length(char **line);
char	*check_rgb(char *tmp);
void	set_rgb(t_idn *idn, char *key, char *value);

//temp functions

void	print_map(t_map *map);
void	print_idn(t_idn *idn);


// temp global vars

int is_ver;
// Manage Player
void	set_map_attribute(t_cub *cub);

#endif