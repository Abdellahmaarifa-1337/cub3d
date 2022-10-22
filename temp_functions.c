/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:13:42 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/18 14:14:08 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub.h"

/***************** PRINT MAP/IDENTIFIERS ********************/
void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->data[i])
	{
		printf("%s\n", map->data[i]);
		i++;
	}
}

void	print_idn(t_idn *idn)
{
	printf("NO = %s\n", idn->_no);
	printf("SO = %s\n", idn->_so);
	printf("WE = %s\n", idn->_we);
	printf("EA = %s\n", idn->_ea);
	printf("F = %d %d %d\n", idn->_f[0], idn->_f[1], idn->_f[2]);
	printf("C = %d %d %d\n", idn->_c[0], idn->_c[1], idn->_c[2]);
}
/***********************************************************/