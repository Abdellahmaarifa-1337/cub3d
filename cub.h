/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/18 13:04:48 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./minilibx/mlx.h"

// GAME VARIBALES

# define EXT_LEN 4
# define EXT ".cub"
# define IDENTIFIERS_NUMBER 6
# define N 1
# define S 2
# define E 3
# define W 4

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
	int		map_capacity;
	int		map_size;
	int		player;
}	t_map;

// Gloabl struct
typedef struct s_cub
{
	t_map	map;
	t_idn	idn;
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

#endif