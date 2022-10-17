#include "../cub.h"


int		is_full_space(char *tmp)
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
		//printf("%s\n", line);
	}	
	//printf("line==%d**\n", last_char);
	//print_map(&(g->map));
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
	g->map.data[g->map.map_size] = NULL;
	// the last line should have only ones ans space and not containe new line
	(void)g;
}