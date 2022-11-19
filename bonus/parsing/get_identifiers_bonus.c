/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifiers_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:27:42 by amaarifa          #+#    #+#             */
/*   Updated: 2022/11/18 12:37:47 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub_bonus.h"

int	set_idn(t_idn *idn, char **line)
{
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
	return (1);
}

int	get_idn(int fd, t_idn *idn)
{
	char	*tmp;
	char	**line;
	int		line_length;
	int		rt;

	rt = 0;
	tmp = get_next_line(fd);
	if (!tmp)
		throw_error("map is incorrect!", 1);
	tmp[ft_strlen(tmp) - 1] = '\0';
	line = ft_split(tmp, ' ');
	line_length = calc_line_length(line);
	if (line_length && (!ft_strncmp(line[0], "F", 2)
			|| !ft_strncmp(line[0], "C", 2)))
		set_rgb(idn, line[0], check_rgb(tmp + 2));
	else if (line_length && line_length != 2 && ft_strncmp(line[0], "F", 2)
		&& ft_strncmp(line[0], "C", 2))
		throw_error("invalid identifier!", 1);
	if (line_length)
		rt = set_idn(idn, line);
	free(tmp);
	free_line(line);
	free(line);
	return (rt);
}

void	get_identifiers(int fd, t_idn *idn)
{
	int		n_idn;

	n_idn = 0;
	while (n_idn < IDENTIFIERS_NUMBER)
		n_idn += get_idn(fd, idn);
}
