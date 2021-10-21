/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:24 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/21 22:47:52 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

/*
 *	first argument is keycode of the pressed key
 *	second argument is the last argument passed in mlx_key_hook
 */
int	key_hook(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == KEY_W)
		return(printf("W\n"));
	if (keycode == KEY_A)
		printf("A\n");
	if (keycode == KEY_S)
		printf("S\n");
	if (keycode == KEY_D)
		printf("D\n");
	return (-1);
}

int	mouse_hook(int button, int x, int y, t_vars * vars)
{
	(void)button;
	(void)vars;
	printf("x: %i   y: %i\n", x, y);
	return (-1);
}

int	main(void)
{
	t_vars		vars;
	t_coords	mouse_pos;
	// t_data	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(vars.mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);
	// mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	vars.coords = &mouse_pos;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	// mlx_mouse_get_pos(vars.win, &mouse_pos.x, &mouse_pos.y);
	mlx_loop(vars.mlx);
	return (0);
}
