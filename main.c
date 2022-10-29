/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkabissi <mkabissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:50 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/29 13:07:30 by mkabissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	g;

	if (ac != 2)
		throw_error("Error : invalid argmuents!", 1);
	g.idn._no = NULL;
	*(g.idn._c) = -1;
	g.idn._ea = NULL;
	*(g.idn._f) = -1;
	g.idn._so = NULL;
	g.idn._we = NULL;
	g.map.height = 0;
	g.map.width = 0;
	g.map.data = (char **)(malloc(sizeof(char *) * 2));
	g.map.map_size = 0;
	g.map.map_capacity = 1;
	g.map.height = 0;
	g.map.width = 0;
	g.map.player = 0;
	g.map.data[g.map.map_capacity] = NULL;
	g.p.inc_pa = INC_PA;
	parse_map(av[1], &g);
	set_map_attribute(&g);
	render_game(&g);
	return (0);
}
