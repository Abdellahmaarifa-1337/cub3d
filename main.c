/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:00:50 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/12 11:13:29 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_cub	g;

	if (ac != 2)
		throw_error("Error : invalid argmuents!", 1);
	parse_map(av[1], &g);
	return (0);
}
