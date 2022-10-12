/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:05 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/12 19:40:01 by amaarifa         ###   ########.fr       */
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
	if (!ft_strncmp(line[0], "NO", 2))
		idn->_no = ft_strdup(line[1]);
	else if (!ft_strncmp(line[0], "SO", 2))
		idn->_so = ft_strdup(line[1]);
	else if (!ft_strncmp(line[0], "WE", 2))
		idn->_we = ft_strdup(line[1]);	
	else if (!ft_strncmp(line[0], "EA", 2))
		idn->_ea = ft_strdup(line[1]);
	else if (!ft_strncmp(line[0], "F", 2))
		idn->_f = ft_strdup(line[1]);
	else if (!ft_strncmp(line[0], "C", 2))
		idn->_c = ft_strdup(line[1]);
	else
		throw_error("invalid identifiers", 1);
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
		if (line_length != 2)
			throw_error("invalid identifier!", 1);
		else
		{
			set_idn(idn, line);
			n_idn++;
		}
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
	printf("F = %s\n", idn->_f);
	printf("C = %s\n", idn->_c);
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
	return tmp;
}

void	get_map(int fd, t_cub *g)
{
	char	*line;

	line = get_first_line(fd);
	
	(void)g;
	printf("%s\n", line);
}

int	parse_map(const char *path, t_cub *g)
{
	int	fd;

	fd = open_file(path);
	get_identifiers(fd, &(g->idn));
	//get_map(fd, g);
	print_idn(&(g->idn));
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
