/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:06:47 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/18 22:23:40 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	get_map(int fd, t_cub *g)
{
	char	*line;
	char	last_char;

	line = get_first_line(fd);
	check_walls(line);
	push_back(&(g->map), line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			break ;
		last_char = line[ft_strlen(line) - 1];
		check_allowed_char(line);
		if (!ft_strncmp(line, "\n", 1))
			throw_error("new line should not be here!", 1);
		push_back(&(g->map), line);
		get_player(&(g->map), line);
	}	
	if (last_char == 10 || (is_full_space(g->map.data[g->map.map_size - 1])))
		throw_error("map should not end with new line", 1);
	check_walls(g->map.data[g->map.map_size - 1]);
	check_player(g->map.player);
	g->map.data[g->map.map_size] = NULL;
}
