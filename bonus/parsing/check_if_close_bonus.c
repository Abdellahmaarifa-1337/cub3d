/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_close_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 12:46:28 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/18 12:31:27 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

void	check_left(t_map *map, size_t i, size_t j)
{
	while (j >= 0)
	{
		if (map->data[i][j] == '1')
			break ;
		if (map->data[i][j] == '0' && map->data[i][j] == map->player)
			break ;
		if (map->data[i][j] == 32)
			throw_error("map should be closed", 1);
		j--;
	}
	if (++j == 0 && map->data[i][j] != '1')
		throw_error("map should be closed", 1);
}

void	check_right(t_map *map, size_t i, size_t j)
{
	while (j < ft_strlen(map->data[i]))
	{
		if (map->data[i][j] == '1')
			break ;
		if (map->data[i][j] == '0' && map->data[i][j] == map->player)
			break ;
		if (map->data[i][j] == 32)
			throw_error("map should be closed", 1);
		j++;
	}
	if (j == ft_strlen(map->data[i]) && map->data[i][j - 1] != '1')
		throw_error("map should be closed", 1);
}

void	check_up(t_map *map, size_t i, size_t j)
{
	while (i >= 0)
	{
		if ((size_t)j >= ft_strlen(map->data[i])
			&& map->data[i + 1][j] != '1')
			throw_error("map should be closed", 1);
		if (map->data[i][j] == '1')
			break ;
		if (map->data[i][j] == '0' && map->data[i][j] == map->player)
			break ;
		if (map->data[i][j] == 32)
			throw_error("map should be closed", 1);
		i--;
	}
	if (++i == 0 && map->data[i][j] != '1')
		throw_error("map should be closed", 1);
}

void	check_down(t_map *map, size_t i, size_t j)
{
	while (i < (size_t)map->map_size)
	{
		if ((size_t)j >= ft_strlen(map->data[i])
			&& map->data[i - 1][j] != '1')
			throw_error("map should be closed", 1);
		if (map->data[i][j] == '1')
			break ;
		if (map->data[i][j] == '0' && map->data[i][j] == map->player)
			break ;
		if (map->data[i][j] == 32)
			throw_error("map should be closed", 1);
		i++;
	}
	if (i == (size_t)map->map_size && map->data[i - 1][j] != '1')
		throw_error("map should be closed", 1);
}

void	check_if_close(t_map *map, size_t i, size_t j)
{
	check_left(map, i, j);
	check_right(map, i, j);
	check_up(map, i, j);
	check_down(map, i, j);
}
