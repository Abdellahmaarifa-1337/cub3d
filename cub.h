/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/14 16:25:26 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "stdio.h"
# include "stdlib.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "fcntl.h"

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

#endif