/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init_and_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:56 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 23:59:01 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_pec(t_map *map, size_t x, size_t y)
{
	if (ft_in_set(map->map[y][x], "P"))
	{
		if (map->count_p == 0)
			map->p_pos = set_coords(x, y);
		else if (map->count_p == 1)
			map->enemy_p_0 = set_coords(x, y);
		else if (map->count_p == 2)
			map->enemy_p_1 = set_coords(x, y);
		map->map[y][x] = '0';
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
