/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_and_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:56 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/17 19:06:51 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_pec(t_map *map, size_t x, size_t y)
{
	if (ft_in_set(map->map[y][x], "P"))
	{
		map->count_p++;
	}
	else if (ft_in_set(map->map[y][x], "E"))
	{
		map->count_e++;
	}
	else if (ft_in_set(map->map[y][x], "C"))
	{
		map->count_c++;
	}
}
