/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:18:03 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 22:01:30 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error(int err_code)
{
	ft_putstr_fd("Error\n", 2);
	if (err_code == EXIT_2D_ARRAY)
		ft_putstr_fd("Failed saving map in 2d array\n", 2);
	else if (err_code == EXIT_RECT)
		ft_putstr_fd("Map is not rectangular\n", 2);
	else if (err_code == EXIT_NOT_WALLED)
		ft_putstr_fd("Map is not walled around the edges\n", 2);
	else if (err_code == EXIT_INVALID_CHAR)
		ft_putstr_fd("Map uses invalid chars (not 1, 0, P, E, C)\n", 2);
	else if (err_code == EXIT_MAP_TOO_SMALL)
		ft_putstr_fd("Map is too small, must be at least 5x3 or 3x5\n", 2);
	else if (err_code == EXIT_NO_PEC)
		ft_putstr_fd("Map does not have at least one of each: P, E, C\n", 2);
	else if (err_code == EXIT_MAP_TOO_BIG)
		ft_putstr_fd("Map is too big, tile size would be too small\n", 2);
	else if (err_code == EXIT_MALLOC_FAILED)
		ft_putstr_fd("Could not allocate memory, malloc returned NULL\n", 2);
	else if (err_code == EXIT_TOO_MANY_P)
		ft_putstr_fd("Map has more than one P\n", 2);
	else if (err_code == EXIT_WRONG_ARGUMENTS)
		ft_putstr_fd("Usage: ./so_long <path to map>\n", 2);
	return (err_code);
}
