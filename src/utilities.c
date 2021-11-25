/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:25:08 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/24 21:03:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coords	set_coords( int x, int y)
{
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_close(int keycode, t_vars *vars)
{
	(void)vars;
	(void)keycode;
	exit(0);
	return (0);
}

int	is_ber_file(char *path)
{
	int	len;

	len = ft_strlen(path);
	len--;
	if (path[len] == 'r' && path[len - 1] == 'e' && path[len - 2] == 'b'
		&& path[len - 3] == '.')
		return (1);
	return (0);
}
