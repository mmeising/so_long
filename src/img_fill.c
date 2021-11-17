/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_fill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 19:20:01 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/17 19:34:17 by mmeising         ###   ########.fr       */
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

void	fill_images(t_vars *vars, int ts)
{
	fill_square(vars->red, RED, ts);
	fill_square(vars->green, GREEN, ts);
	ft_put_circle(ts / 2, vars->player, TRANSP, set_coords(ts / 2, ts / 2));
}
