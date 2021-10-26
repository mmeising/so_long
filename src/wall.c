/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 21:28:41 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/26 22:18:01 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_wall(t_vars *vars, int x, int y)
{
	int	i;
	int	count;
	int	change;
	int	ts;

	i = 0;
	count = 0;
	ts = vars->map.size_tile;
	x *= ts;
	y *= ts;
	while (count < ts * 4)
	{
		my_mlx_pixel_put(vars->img, x, y, vars->color);
		if (count >= 0 && count < ts * 2)
			change = 1;
		else if (count >= ts * 2)
			change = -1;
		if ((count >= 0 && count < ts) || (count >= ts * 2 && count < ts * 3))
			x += change;
		else
			y += change;
		count++;
	}
}

void	put_walls_on_screen(t_vars *vars)
{
	prnt("put walls on screen\n");
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 10)
	{
		put_wall(vars, x, 0);
		x++;
	}
	x = 0;
	while (y < 10)
	{
		put_wall(vars, 0, y);
		y++;
	}
}