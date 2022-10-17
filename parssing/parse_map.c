/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:05 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/17 16:55:18 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"
void print_map(t_map *map)
{
	int	i;
	
	i = 0;
	while (map->data[i])
	{
		printf("%s\n", map->data[i]);
		i++;
	}
}

int	open_file(const char *path)
{
	size_t	path_len;
	int		fd;

	fd = 0;
	path_len = ft_strlen(path);
	if (path_len > EXT_LEN
		&& !ft_strncmp(EXT
			, ft_substr(path, path_len - EXT_LEN, EXT_LEN), EXT_LEN))
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
		{
			perror(NULL);
			throw_error(NULL, 1);
		}
	}
	else
		throw_error("error file extention!\n", 1);
	return (fd);
}





void print_idn(t_idn *idn)
{
	printf("NO = %s\n", idn->_no);
	printf("SO = %s\n", idn->_so);
	printf("WE = %s\n", idn->_we);
	printf("EA = %s\n", idn->_ea);
	printf("F = %d %d %d\n", idn->_f[0], idn->_f[1], idn->_f[2]);
	printf("C = %d %d %d\n", idn->_c[0], idn->_c[1], idn->_c[2]);
}


void	check_if_close(t_map *map, int i, int j)
{
	size_t	tmp;

	// check left
	tmp = j;
	while (tmp >= 0)
	{
		if (map->data[i][tmp] == '1')
			break ;
		if (map->data[i][tmp] == '0' && map->data[i][j]  == map->player)
			break ;
		if (map->data[i][tmp] == 32)
			throw_error("map should be closed", 1);
		tmp--;
	}
	if (++tmp == 0 && map->data[i][tmp] != '1')
		throw_error("map should be closed", 1);
	
	// check right
	tmp = j;
	while (tmp < ft_strlen(map->data[i]))
	{
		if (map->data[i][tmp] == '1')
			break ;
		if (map->data[i][tmp] == '0' && map->data[i][j]  == map->player)
			break ;
		if (map->data[i][tmp] == 32)
			throw_error("map should be closed", 1);
		tmp++;
	}
	if (tmp == ft_strlen(map->data[i]) && map->data[i][tmp - 1] != '1')
		throw_error("map should be closed", 1);
	// checck up
	tmp = i;
	while (tmp >= 0)
	{
		//printf("char in testing : %c\n", map->data[tmp][j]);
		if ((size_t)j >= ft_strlen(map->data[tmp])
			&& map->data[tmp + 1][j] != '1')
			throw_error("map should be closed", 1);
		if (map->data[tmp][j] == '1')
			break ;
		if (map->data[tmp][j] == '0' && map->data[i][j]  == map->player)
			break ;
		if (map->data[tmp][j] == 32)
			throw_error("map should be closed", 1);
		tmp--;
	}
	if (++tmp == 0 && map->data[tmp][j] != '1')
		throw_error("map should be closed", 1);

	// check down
	tmp = i;
	while (tmp < (size_t)map->map_size)
	{
		//printf("char in testing : %c\n", map->data[tmp][j]);
		if ((size_t)j >= ft_strlen(map->data[tmp]) && map->data[tmp - 1][j] != '1')
			throw_error("map should be closed", 1);
		if (map->data[tmp][j] == '1')
			break ;
		if (map->data[tmp][j] == '0' && map->data[i][j] == map->player)
			break ;
		if (map->data[tmp][j] == 32)
			throw_error("map should be closed", 1);
		tmp++;
	}
	if (tmp == (size_t)map->map_size && map->data[tmp - 1][j] != '1')
		throw_error("map should be closed", 1);

}

void	check_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(map->data[i])
	{
		j = 0;
		//ft_strlen(map->data[i]);
		while (map->data[i][j])
		{
		//printf("%d\n",j);
			if (map->data[i][j] == '0'|| map->data[i][j] == map->player)
				check_if_close(map, i, j);
			j++;
		}
		i++;
	}
}


void check_idn(t_idn *idn)
{
	if (open(idn->_ea, O_RDONLY) == -1 || open(idn->_no, O_RDONLY) == -1 
		|| open(idn->_so, O_RDONLY) == -1  || open(idn->_we, O_RDONLY) == -1 )
		throw_error("file not exist", 1);
}

int	parse_map(const char *path, t_cub *g)
{
	int	fd;

	fd = open_file(path);
	get_identifiers(fd, &(g->idn));
	check_idn(&(g->idn));
	if (*(g->idn._c) == -1 || !g->idn._ea || *(g->idn._f) == -1 || !g->idn._no || !g->idn._so || !g->idn._we)
		throw_error("Identifier error!", 1);
	get_map(fd, g);
	check_map(&(g->map));
	print_idn(&(g->idn));
	print_map(&(g->map));
	//printf("%d\n", g->map.map_size);
	// (void)g;
	// char	tmp[1000];
	// char	*str;
	// char	*t;

	// str = ft_strdup("");
	// while (read(fd, tmp, 1000) > 0)
	// {
	// 	t = str;
	// 	str = ft_strjoin(str, tmp);
	// 	free(t);
	// }
	// printf("\nmap: \n%s\n", str);
	return (0);
}
