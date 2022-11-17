/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:01:02 by amaarifa          #+#    #+#             */
/*   Updated: 2022/10/12 13:10:15 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	throw_error(const char *error, int _ex)
{
	if (error)
		printf("%s\n", error);
	if (_ex)
		exit(_ex);
}
