/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ex_coll_enemy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:26:15 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/20 02:44:31 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_exit(t_data *ex, int color, int ts)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < ts)
	{
		my_mlx_pixel_put(ex, x, y, color);
		x++;
		y++;
	}
	x = 0;
	while (x < ts)
	{
		my_mlx_pixel_put(ex, x, y, color);
		x++;
		y--;
	}
}

void	create_coll(t_data *coll, int color, int ts)
{
	int	r;

	r = ts / 4;
	ft_put_circle(r, coll, color, set_coords(ts / 2, ts / 2));
	while (r > 1)
	{
		ft_put_circle(r, coll, color, set_coords(ts / 2, ts / 2));
		r--;
	}
}

void	create_enemy(t_data *enemy, int color, int ts)
{
	int	x;
	int	y;
	int	r;

	r = ts / 3;
	ft_put_circle(r, enemy, color, set_coords(ts / 2, ts / 2));
	x = ts / 6;
	y = ts / 6;
	while (y < 5 * ts / 6)
	{
		my_mlx_pixel_put(enemy, x, y, color);
		x++;
		y++;
	}
	x = ts / 6;
	while (x < 5 * ts / 6 )
	{
		my_mlx_pixel_put(enemy, x, y, color);
		x++;
		y--;
	}
}
