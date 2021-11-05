/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:24 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 01:37:50 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	prnt("my mlx pixel put\n");
	char	*dst;

	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	ft_close(int keycode, t_vars *vars)
{
	prnt("close\n");
	(void)vars;
	(void)keycode;
	exit(0);
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	prnt("render next frame\n");
	if (vars->img->img)
	{
		prnt("mlx destroy image\n");
		mlx_destroy_image(vars->mlx, vars->img->img);
	}
	prnt("mlx new image\n");
	vars->img->img = mlx_new_image(vars->mlx, 1920, 1080);
	prnt("mlx get data addr\n");
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpp,
			&vars->img->line_length, &vars->img->endian);
	put_player_on_screen(vars);
	put_walls_on_screen(vars);
	// ft_background_circles(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

int	main(void)
{
	t_vars		vars;

	vars.map = check_map("map1.ber");
	prnt("init\n");
	vars.mlx = mlx_init();
	prnt("new window\n");
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	prnt("vars.img alloc\n");
	vars.img = malloc(sizeof(*(vars.img)));
	if (vars.img == NULL)
		return (0);
	vars.map->t_s = 151;
	vars.color = 0x00FF0000;
	prnt("new image\n");
	vars.img->img = mlx_new_image(vars.mlx, 1920, 1080);
	prnt("get data addr\n");
	vars.img->addr = mlx_get_data_addr(vars.img->img, &vars.img->bpp,
			&vars.img->line_length, &vars.img->endian);
	vars.player_pos.x = 1;// * vars.map.t_s;
	vars.player_pos.y = 1;// * vars.map.t_s;
	prnt("mlx mouse hook\n");
	mlx_mouse_hook(vars.win, mouse_hook, &vars);
	prnt("mlx key hook\n");
	mlx_key_hook(vars.win, key_hook, &vars);
	prnt("mlx hook\n");
	mlx_hook(vars.win, 17, 1L << 17, ft_close, &vars);
	prnt("mlx loop hook\n");
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	prnt("mlx looop\n");
	mlx_loop(vars.mlx);
	return (0);
}
