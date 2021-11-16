/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:41:54 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/16 19:04:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**save_in_2d_array(t_map *map)
{
	int		fd;
	char	*temp;
	char	*line;

	fd = open(map->path, O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		exit(EXIT_2D_ARRAY);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		line = ft_strcon(&line, &temp);
	}
	return (ft_split(line, '\n'));
}

static void	is_rectangle_and_big_enough(t_map *map)
{
	map->sz_x = ft_strlen(map->map[0]);
	while (map->map[map->sz_y])
	{
		if (map->sz_x == ft_strlen(map->map[map->sz_y]))
			map->sz_y++;
		else
			exit(error(EXIT_RECT));
	}
	if (!((map->sz_x >= 3 && map->sz_y >= 5)
			|| (map->sz_x >= 5 && map->sz_y >= 3)))
		exit(error(EXIT_MAP_TOO_SMALL));
}

static void	is_walled_and_valid_chars(t_map *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map->sz_y)
	{
		i = 0;
		while (i < map->sz_x)
		{
			if (i == 0 || i == map->sz_x - 1 || j == 0 || j == map->sz_y - 1)
			{
				if (map->map[j][0] != '1' ||
					map->map[j][map->sz_x - 1] != '1' ||
					map->map[0][i] != '1' || map->map[map->sz_y - 1][i] != '1')
					exit(error(EXIT_NOT_WALLED));
			}
			else if (!ft_in_set(map->map[j][i], "10PEC"))
				exit(error(EXIT_INVALID_CHAR));
			i++;
		}
		j++;
	}
}

void	check_and_list_pec1(t_map *map)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < map->sz_y)
	{
		i = 0;
		while (i < map->sz_x)
		{
			if (ft_in_set(map->map[j][i], "1PEC"))
				is_pec1(map, i, j);
			i++;
		}
		j++;
	}
	if (!(map->count_p && map->count_e && map->count_c))
		exit(error(EXIT_NO_PEC));
}

t_map	*check_map(char *path)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (map == NULL)
		return (NULL);
	init_map_values(map, path);
	map->map = save_in_2d_array(map);
	if (map->map == NULL)
		exit(error(EXIT_2D_ARRAY));
	is_rectangle_and_big_enough(map);
	is_walled_and_valid_chars(map);
	check_and_list_pec1(map);
	set_tile_size(map);
	// printf("outside: wall: x:%d y: %d\n", map->list_1->pos.x, map->list_1->pos.y);
	// while (map->list_1->next)
	// {
	// 	if (map->list_1)
	// 		printf("wall: x:%d y: %d\n", map->list_1->pos.x, map->list_1->pos.y);
	// 	map->list_1 = map->list_1->next;
	// }
	while (map->list_1)
	{
		printf("wall: x: %i\t\ty: %i\n", map->list_1->pos.x, map->list_1->pos.y);
		map->list_1 = map->list_1->next;
	}
	while (map->list_c)
	{
		printf("p: x: %i\t\ty: %i\n", map->list_c->pos.x, map->list_c->pos.y);
		map->list_c = map->list_c->next;
	}
	while (map->list_e)
	{
		printf("e: x: %i\t\ty: %i\n", map->list_e->pos.x, map->list_e->pos.y);
		map->list_e = map->list_e->next;
	}
	while (map->list_p)
	{
		printf("p: x: %i\t\ty: %i\n",map->list_p->pos.x, map->list_p->pos.y);
		map->list_p = map->list_p->next;
	}
	// exit(0);
	return (map);
}
