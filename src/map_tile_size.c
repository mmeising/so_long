/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tile_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 17:20:27 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/16 19:04:03 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	recursive_t_s(t_map *map)
{
	if (map->sz_x * map->t_s > 1920)
	{
		map->t_s -= 2;
		// printf("tile_size: %i\n", map->t_s);
		recursive_t_s(map);
	}
	else if (map->sz_y * map->t_s > 1080)
	{
		map->t_s -= 2;
		// printf("tile_size: %i\n", map->t_s);
		recursive_t_s(map);
	}
	else if (map->t_s < 25)
		exit(error(EXIT_MAP_TOO_BIG));
	else
		return ;
}

void	set_tile_size(t_map *map)
{
	map->t_s = 101;
	recursive_t_s(map);
	printf("final tile_size: %i\n", map->t_s);
	printf("tile_size * x: %lu\ntile_size * y: %lu\n", map->t_s * map->sz_x, map->t_s * map->sz_y);
	exit(0);//exit
}