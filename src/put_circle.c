/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_circle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 19:33:00 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/26 22:17:32 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 *	thanks to dereferencing dst which right before was set to an address
 *	dependant on data->addr, we can change the color without a return value.
 */
/*
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}
*/
void	ft_put_symmetric_circle(t_data *img, t_coords outer, int color,
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
 *	use ft_set_coords(x, y) as last argument to set center.
 */
void	ft_put_circle(int r, t_data *img, unsigned int color, t_coords middle)
{
	prnt("put circle\n");
	int			d;
	t_coords	outer;

	d = -r;
	outer.x = r;
	outer.y = 0;
	middle.x += r;
	middle.y += r;
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

t_coords	ft_set_coords( int x, int y)
{
	prnt("set coords\n");
	t_coords	coords;

	coords.x = x;
	coords.y = y;
	return (coords);
}

/*
int	main(void)
{
	void			*mlx;
	void			*mlx_win;
	t_data			img;
	unsigned int	color;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");//create window
	img.img = mlx_new_image(mlx, 1920, 1080);	//create a new image to 
												//put pixels on
	img.addr = mlx_get_data_addr(img.img, &img.bpp,
			&img.line_length, &img.endian);//basically initialize that image?
	color = 0x00FF0000;
	ft_put_circle(300, &img, color, ft_set_coords(1000, 400));//choose to 
											//create this circle on the image
	ft_put_circle(100, &img, 0x0000FF00, ft_set_coords(1100, 500));//another 
													//circle on same image
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);//now putting this 
								//whole image to our window - updating the frame
	mlx_loop(mlx);
	return (0);
}
*/