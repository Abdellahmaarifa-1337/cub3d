/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:27:42 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/18 11:46:02 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	else if (ft_strncmp(line[0], "F", 2) && ft_strncmp(line[0], "C", 2))
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
			throw_error("map is incorrect!", 1);
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
			set_rgb(idn, line[0], check_rgb(tmp + 2));
		else if (line_length != 2 && ft_strncmp(line[0], "F", 2)
			&& ft_strncmp(line[0], "C", 2))
			throw_error("invalid identifier!", 1);
		set_idn(idn, line);
		n_idn++;
		free(tmp);
		free_line(line);
		free(line);
	}
}
