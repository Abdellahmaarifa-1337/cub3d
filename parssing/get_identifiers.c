
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