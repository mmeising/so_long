/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:33:00 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 02:56:13 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_put_symmetric_circle(t_data *img, t_coords outer, int color,
								t_coords middle)
{
	my_mlx_pixel_put(img, middle.x + outer.x, middle.y + outer.y, color);
	my_mlx_pixel_put(img, middle.x + outer.y, middle.y + outer.x, color);
	my_mlx_pixel_put(img, middle.x + outer.y, middle.y - outer.x, color);
	my_mlx_pixel_put(img, middle.x + outer.x, middle.y - outer.y, color);
	my_mlx_pixel_put(img, middle.x - outer.x, middle.y - outer.y, color);
	my_mlx_pixel_put(img, middle.x - outer.y, middle.y - outer.x, color);
	my_mlx_pixel_put(img, middle.x - outer.y, middle.y + outer.x, color);
	my_mlx_pixel_put(img, middle.x - outer.x, middle.y + outer.y, color);
}

/*
 *	puts circle with radius r and color color with center at middle.
 *	use set_coords(x, y) as last argument to set center.
 */
void	ft_put_circle(int r, t_data *img, unsigned int color, t_coords middle)
{
	int			d;
	t_coords	outer;

	d = -r;
	outer.x = r;
	outer.y = 0;
	while (outer.y <= outer.x)
	{
		ft_put_symmetric_circle(img, outer, color, middle);
		d = d + 2 * outer.y + 1;
		outer.y = outer.y + 1;
		if (d > 0)
		{
			d = d - 2 * outer.x + 2;
			outer.x = outer.x - 1;
		}
	}
}
