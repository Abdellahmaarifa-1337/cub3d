/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniMap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:47:57 by mkabissi          #+#    #+#             */
/*   Updated: 2022/10/19 14:03:02 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_H
# define MINIMAP_H

# include "../cub.h"
# define	MAP	cub->map
# define	PLY cub->p

struct	t_cub;

# define EMPTY	0x494949	//0x0
# define WALL	0xE1E6E6
# define PLAYER	0xF5DC50
# define CELL	45

void	execute_MiniMap(void* mlx, void* mlx_win, t_cub *cub);

#endif