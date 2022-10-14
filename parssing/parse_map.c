/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:05 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/14 17:46:14 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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

int	calc_line_length(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i++])
		free(line[i]);
}

void	set_idn(t_idn *idn, char **line)
{
	//char	*tmp;
	if (!ft_strncmp(line[0], "NO", 2))
		idn->_no = ft_strdup(line[1]);
	else if (!ft_strncmp(line[0], "SO", 2))
		idn->_so = ft_strdup(line[1]);
	else if (!ft_strncmp(line[0], "WE", 2))
		idn->_we = ft_strdup(line[1]);	
	else if (!ft_strncmp(line[0], "EA", 2))
		idn->_ea = ft_strdup(line[1]);
	else if (ft_strncmp(line[0], "F", 2) && ft_strncmp(line[0], "C", 2))
		throw_error("invalid identifiers", 1);
}

char *check_rgb(char *tmp)
{
	int		i;
	int		j;
	char	*cop;
	int		comma;

	//printf("tmp = %s", tmp + 2);
	cop = (char *)malloc(sizeof(char) * ft_strlen(tmp));
	i = 0;
	j = 0;
	tmp += 2;
	comma = 0;
	while (tmp[i])
	{
		if (tmp[i] != 32 && tmp[i] != ',' && !ft_isdigit(tmp[i]))
			throw_error("err9", 1);
		if (tmp[i] == 32)
			i++;
		else
		{
			cop[j] = tmp[i];
			if (cop[j] == ',')
				comma++;
			if (j > 0 && cop[j] == ',' && cop[j - 1] == ',')
				throw_error("invalid6", 1);	
			j++;
			i++;
		}
	}
	cop[j] = '\0';
	if (cop[0] == ',' || cop[ft_strlen(cop) - 1] == ',')
		throw_error("error!", 1);
	if (comma != 2)
		throw_error("erro7", 1);
	return (cop);
}

void set_rgb(t_idn *idn,char *key, char *value)
{
	char	**line;

	line = ft_split(value, ',');

	if (!ft_strncmp(key, "F", 2))
	{
		idn->_f[0] = ft_atoi(line[0]);
		idn->_f[1] = ft_atoi(line[1]);
		idn->_f[2] = ft_atoi(line[2]);
		if ((idn->_f[0] < 0 || idn->_f[0] > 255)
			|| (idn->_f[1] < 0 || idn->_f[1] > 255)
			|| (idn->_f[2] < 0 || idn->_f[2] > 255))
				throw_error("err99", 1);
	}
	if (!ft_strncmp(key, "C", 2))
	{
		idn->_c[0] = ft_atoi(line[0]);
		idn->_c[1] = ft_atoi(line[1]);
		idn->_c[2] = ft_atoi(line[2]);
		if ((idn->_c[0] < 0 || idn->_c[0] > 255)
			|| (idn->_c[1] < 0 || idn->_c[1] > 255)
			|| (idn->_c[2] < 0 || idn->_c[2] > 255))
				throw_error("err99", 1);
	}
}

void	get_identifiers(int fd, t_idn *idn)
{
	int		n_idn;
	char	*tmp;
	char	**line;
	int		line_length;

	n_idn = 0;
	while (n_idn < IDENTIFIERS_NUMBER)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			throw_error("map is empty!", 1);
		tmp[ft_strlen(tmp) - 1] = '\0';
		line = ft_split(tmp, ' ');
		line_length = calc_line_length(line);
		if (!line_length)
		{
			free(tmp);
			free_line(line);
			free(line);
			continue ;
		}
		if ((!ft_strncmp(line[0], "F", 2) || !ft_strncmp(line[0], "C", 2)))
		{
			
			set_rgb(idn, line[0], check_rgb(tmp));
			//throw_error("invalid identifier!", 1);
		}
		else if (line_length != 2 && ft_strncmp(line[0], "F", 2) && ft_strncmp(line[0], "C", 2))
		{
			printf("line %s\n", line[0]);
			throw_error("invalid identifier!", 1);
		}

		set_idn(idn, line);
		n_idn++;

		free(tmp);
		free_line(line);
		free(line);
	}
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

int		is_full_space(char *tmp)
{
	int	i;

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
			throw_error("the map should be closed by walls!", 1);
		i++;
	}
}

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
		free (map->data[i]);
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
	//printf("size : %d , capacity : %d\n", map->map_size, map->map_capacity);
	map->data[map->map_size] = ft_strdup(line);
	if ((map->data[map->map_size])[ft_strlen(line) - 1] == '\n')
		(map->data[map->map_size])[ft_strlen(line) - 1] = '\0';
	if (!ft_strncmp(map->data[map->map_size], "\n", 2))
		throw_error("empty line not allowed in the map", 1);
	map->map_size += 1;
}

int get_char(char *s, int c)
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

void	get_player(t_map *map, char *line)
{
	int p = get_char(line, 'N') + get_char(line, 'S') + get_char(line, 'E') + get_char(line, 'W');
	// if (p && map->player)
	// 	throw_error("there is more than one", 1);
	// else if (p)
	map->player += p;
	//if (ft_strchr(line, 'N') )
}

void check_allowed_char(char *s)
{
	int i;

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

void	get_map(int fd, t_cub *g)
{
	char	*line;
	char	last_char;

	line = get_first_line(fd);
	//the first line should only have space or ones
	check_walls(line);
	push_back(&(g->map), line);
	while (line)
	{
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
	//printf("line==%d**\n", last_char);
	if (last_char == 10 || (is_full_space(g->map.data[g->map.map_size - 1])))
		throw_error("map should not end with new line", 1);
	check_walls(g->map.data[g->map.map_size - 1]);
	 if (!g->map.player)
	 	throw_error("there is no player!", 1);
	if ( g->map.player != 'N' && g->map.player != 'S' 
		&& g->map.player != 'E' && g->map.player != 'W')
				throw_error("there more then one player", 1);
	// the player should be just onece in the map
	
	// any new line here is error

	// the first char in each line should be a 1 and also tha last non space one

	// the last line should have only ones ans space and not containe new line
	(void)g;
	printf("%s\n", line);
}

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


void	check_if_close(t_map *map, int i, int j)
{
	size_t	tmp;

	// check left
	tmp = j;
	while (tmp >= 0)
	{
		if (map->data[i][tmp] == '1')
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
		if ((size_t)j >= ft_strlen(map->data[tmp]) && map->data[tmp + 1][j] != '1')
			throw_error("map should be closed", 1);
		if (map->data[tmp][j] == '1')
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
		while (map->data[i][j])
		{
			if (map->data[i][j] == '0')
				check_if_close(map, i, j);
			j++;
		}
		i++;
	}
}

int	parse_map(const char *path, t_cub *g)
{
	int	fd;

	fd = open_file(path);
	get_identifiers(fd, &(g->idn));
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
