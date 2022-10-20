/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:06:54 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/18 22:20:49 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	realloc_map(t_map *map)
{
	char	**new_data;
	int		i;

	map->map_capacity = map->map_capacity * 2;
	new_data = (char **)malloc(sizeof(char *) * (map->map_capacity + 1));
	i = 0;
	while (i < map->map_size)
	{
		new_data[i] = ft_strdup(map->data[i]);
		free(map->data[i]);
		i++;
	}
	new_data[i] = NULL;
	free(map->data);
	map->data = new_data;
}

void	push_back(t_map *map, char *line)
{
	if (map->map_capacity == map->map_size)
		realloc_map(map);
	map->data[map->map_size] = ft_strdup(line);
	if ((map->data[map->map_size])[ft_strlen(line) - 1] == '\n')
		(map->data[map->map_size])[ft_strlen(line) - 1] = '\0';
	if (!ft_strncmp(map->data[map->map_size], "\n", 2))
		throw_error("empty line not allowed in the map", 1);
	map->map_size += 1;
}

int	get_char(char *s, int c)
{
	int		i;
	int		ch;

	ch = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			ch += c;
		}
		i++;
	}
	return (ch);
}

int	is_full_space(char *tmp)
{
	int	i;

	if (tmp[ft_strlen(tmp) - 1] == '\n')
		tmp[ft_strlen(tmp) - 1] = '\0';
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] != 32)
			return (0);
		i++;
	}
	return (1);
}
