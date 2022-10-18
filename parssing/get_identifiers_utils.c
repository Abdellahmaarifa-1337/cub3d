/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifiers_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:30:55 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/18 12:12:56 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	free_line(char **line)
{
	int	i;

	i = 0;
	while (line[i++])
		free(line[i]);
}

int	calc_line_length(char **line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	return (i);
}

char	*check_rgb(char *tmp)
{
	int		i;
	int		j;
	char	*cop;
	int		comma;

	cop = (char *)malloc(sizeof(char) * ft_strlen(tmp));
	i = -1;
	j = 0;
	comma = 0;
	while (tmp[++i])
	{
		if (tmp[i] != 32 && tmp[i] != ',' && !ft_isdigit(tmp[i]))
			throw_error("err9", 1);
		else if (tmp[i] != 32)
		{
			cop[j] = tmp[i];
			if (cop[j] == ',' && ++comma && j > 0 && cop[j - 1] == ',')
				throw_error("invalid6", 1);
			j++;
		}
	}
	cop[j] = '\0';
	if (cop[0] == ',' || cop[ft_strlen(cop) - 1] == ',' || comma != 2)
		throw_error("error!8", 1);
	return (cop);
}

void	set_rgb(t_idn *idn, char *key, char *value)
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
