/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:56 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/12 15:28:31 by amaarifa         ###   ########.fr       */
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

typedef struct s_idn
{
	char	*_no;
	char	*_so;
	char	*_we;
	char	*_ea;
	char	*_f;
	char	*_c;
}	t_idn;

// Gloabl struct
typedef struct s_cub
{
	char	**map;
	t_idn	idn;
}	t_cub;

int		parse_map(const char *path, t_cub *g);
void	throw_error(const char *error, int _ex);

#endif