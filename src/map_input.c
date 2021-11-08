/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:41:54 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/08 18:46:31 by mmeising         ###   ########.fr       */
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
		exit(0);
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		line = ft_strcon(&line, &temp);
	}
	return (ft_split(line, '\n'));
}

static void	is_rectangle(t_map *map)
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
	map->sz_y = 0;
	map->count_p = 0;
	map->count_e = 0;
	map->count_c = 0;
	map->list_p = NULL;
	map->list_e = NULL;
	map->list_c = NULL;
	map->list_1 = NULL;
	map->path = path;
	map->map = save_in_2d_array(map);
	if (map->map == NULL)
		exit(error(EXIT_2D_ARRAY));
	is_rectangle(map);
	is_walled_and_valid_chars(map);
	check_and_list_pec1(map);
	// printf("outside: wall: x:%d y: %d\n", map->list_1->pos.x, map->list_1->pos.y);
	// while (map->list_1->next)
	// {
	// 	if (map->list_1)
	// 		printf("wall: x:%d y: %d\n", map->list_1->pos.x, map->list_1->pos.y);
	// 	map->list_1 = map->list_1->next;
	// }
	exit(0);
	return (map);
}
