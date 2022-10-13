/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:50 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/14 00:30:31 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	g;

	if (ac != 2)
		throw_error("Error : invalid argmuents!", 1);
	g.idn._no = NULL;
	g.idn._c = NULL;
	g.idn._ea = NULL;
	g.idn._f = NULL;
	g.idn._so = NULL;
	g.idn._we = NULL;
	g.map.data = (char **)(malloc(sizeof(char *) * 2));
	g.map.map_size = 0;
	g.map.map_capacity = 1;
	g.map.player = 0;
	g.map.data[g.map.map_capacity] = NULL;
	parse_map(av[1], &g);
	return (0);
}
