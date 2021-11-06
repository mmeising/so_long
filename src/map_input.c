/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:41:54 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 17:57:56 by mmeising         ###   ########.fr       */
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

t_map	*check_map(char *path)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (map == NULL)
		return (NULL);
	map->path = path;
	map->map = save_in_2d_array(map);
	while (*map->map)
	{
		printf("map: %s\n", *map->map);
		map->map++;
	}
	return (map);
}
