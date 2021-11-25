/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_nl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:11:13 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/25 17:44:36 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 *	checks if the map saved in line has newlines at the beginning or the end of
 *	file or an empty line in between. Returns 1 if so, else returns 0.
 */
int	nl_map_fail(char *line)
{
	int	i;

	if (line[0] == '\n' || line[ft_strlen(line) - 1] == '\n')
		return (1);
	i = 1;
	while (line[i + 1])
	{
		if (line[i] == '\n' && line[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}
