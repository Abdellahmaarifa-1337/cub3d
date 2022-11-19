/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:18:15 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/18 12:31:27 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	check_player(int player)
{
	if (!player)
		throw_error("there is no player!", 1);
	if (player != 'N' && player != 'S'
		&& player != 'E' && player != 'W')
		throw_error("there more then one player", 1);
}

char	*get_first_line(int fd)
{
	char	*tmp;
	int		player;

	player = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			throw_error("no map", 1);
		if (is_full_space(tmp) || !ft_strncmp(tmp, "\n", 1))
		{
			free(tmp);
			continue ;
		}
		break ;
	}
	return (tmp);
}

void	check_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != 32)
			throw_error("Invalid map", 1);
		i++;
	}
}

void	get_player(t_map *map, char *line)
{
	int	p;

	p = get_char(line, 'N') + get_char(line, 'S') + get_char(line, 'E')
		+ get_char(line, 'W');
	map->player += p;
}

void	check_allowed_char(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '0' && s[i] != '1'
			&& s[i] != 32 && s[i] != 'N' && s[i] != 'S'
			&& s[i] != 'E' && s[i] != 'W' && s[i] != 10)
		{
			throw_error("not allowed characters", 1);
		}
		i++;
	}
}
