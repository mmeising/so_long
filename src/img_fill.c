/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:20:01 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 18:37:59 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_square(t_data *square, int color, int ts)
{
	int	i;
	int	j;

	j = 0;
	while (j < ts)
	{
		i = 0;
		while (i < ts)
		{
			my_mlx_pixel_put(square, i, j, color);
			i++;
		}
		j++;
	}
}

void	create_wall(t_data *wall, int color, int ts)
{
	int	x;
	int	y;

	x = 0;
	while (x < ts)
	{
		my_mlx_pixel_put(wall, x, 0, color);
		my_mlx_pixel_put(wall, x, ts - 1, color);
		x++;
	}
	y = 0;
	while (y < ts)
	{
		my_mlx_pixel_put(wall, 0, y, color);
		my_mlx_pixel_put(wall, ts - 1, y, color);
		y++;
	}
}

void	create_player(t_data *player, int color, int ts)
{
	int	r;

	r = ts / 2;
	ft_put_circle(r, player, color, set_coords(ts / 2, ts / 2));
	while (r > 1)
	{
		if (r % 5 == 0)
			ft_put_circle(r, player, color, set_coords(ts / 2, ts / 2));
		r--;
	}
}

void	fill_images(t_vars *vars, int ts)
{
	fill_square(vars->red, RED, ts);
	fill_square(vars->green, GREEN, ts);
	create_wall(vars->wall, TRANSP, ts);
	create_player(vars->player, TRANSP, ts);
	create_exit(vars->ex, TRANSP, ts);
	create_coll(vars->coll, TRANSP, ts);
}
