/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:05 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/18 12:31:27 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	open_file(const char *path)
{
	size_t		path_len;
	int			fd;
	const char	*tmp;
	char		*path_ext;

	fd = 0;
	path_len = ft_strlen(path);
	if (ft_strrchr(path, '/'))
	{
		tmp = ft_strrchr(path, '/') + 1;
		path_len = ft_strlen(tmp);
	}
	else
		tmp = path;
	path_ext = ft_substr(tmp, path_len - EXT_LEN, EXT_LEN);
	if (path_len > EXT_LEN && !ft_strncmp(EXT, path_ext, EXT_LEN))
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			throw_error("file error!", 1);
	}
	else
		throw_error("error file extention!\n", 1);
	free(path_ext);
	return (fd);
}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] == '0' || map->data[i][j] == map->player)
				check_if_close(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_idn(t_idn *idn)
{
	if ((idn->_ea && open(idn->_ea, O_RDONLY) == -1)
		|| (idn->_no && open(idn->_no, O_RDONLY) == -1)
		|| (idn->_so && open(idn->_so, O_RDONLY) == -1)
		|| (idn->_we && open(idn->_we, O_RDONLY) == -1))
		throw_error("file not exist", 1);
}

int	parse_map(const char *path, t_cub *g)
{
	int	fd;

	fd = open_file(path);
	get_identifiers(fd, &(g->idn));
	check_idn(&(g->idn));
	if (*(g->idn._c) == -1 || !g->idn._ea || *(g->idn._f) == -1 || !g->idn._no
		|| !g->idn._so || !g->idn._we)
		throw_error("Identifier error!", 1);
	get_map(fd, g);
	check_map(&(g->map));
	return (0);
}
