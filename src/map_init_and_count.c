/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:56 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/16 21:10:45 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map_values(t_map *map, char *path)
{
	map->sz_y = 0;
	map->count_p = 0;
	map->count_e = 0;
	map->count_c = 0;
	// map->list_p = NULL;
	// map->list_e = NULL;
	// map->list_c = NULL;
	// map->list_1 = NULL;
	map->path = path;
}

void	is_pec1(t_map *map, size_t x, size_t y)
{
	if (ft_in_set(map->map[y][x], "P"))
	{
		map->count_p++;
		// map->list_p = lstadd_front(&map->list_p, ft_set_coords(x, y));
	}
	else if (ft_in_set(map->map[y][x], "E"))
	{
		map->count_e++;
		// map->list_e = lstadd_front(&map->list_e, ft_set_coords(x, y));
	}
	else if (ft_in_set(map->map[y][x], "C"))
	{
		map->count_c++;
		// map->list_c = lstadd_front(&map->list_c, ft_set_coords(x, y));
	}
	else if (ft_in_set(map->map[y][x], "1"))
	{
		// map->list_1 = lstadd_front(&map->list_1, ft_set_coords(x, y));
	}
	// init_lists(map);
}
