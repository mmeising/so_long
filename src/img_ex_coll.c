/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ex_coll.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:26:15 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 19:11:12 by mmeising         ###   ########.fr       */
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
		if (r % 2 == 0)
			ft_put_circle(r, coll, color, set_coords(ts / 2, ts / 2));
		r--;
	}
}
