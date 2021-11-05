/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:41:54 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 01:35:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid(t_map *map)
{
	int		fd;
	char	*temp;
	char	*line;
	int		read_flag;
	int		i = 0;

	fd = open(map->path, O_RDONLY);
	line = get_next_line(fd);
	printf("%i?\n", fd);
	if (line == NULL)
		exit(0);
	read_flag = 1;
	while (read_flag)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			exit(0);
		if (temp[0] == '\0')
			read_flag = 0;
		line = ft_strcon(&line, &temp);
	}
	map->map = ft_split(line, '\n');
	while (map->map[i])
		printf("%s\n", map->map[i++]);
	exit(0);
}

t_map	*check_map(char *path)
{
	t_map	*map;

	map = malloc(sizeof(*map));
	if (map == NULL)
		return (NULL);
	map->path = path;
	is_valid(map);
	return (map);
}
