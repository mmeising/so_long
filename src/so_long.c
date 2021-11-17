/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:24 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/17 22:34:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	// prnt("my mlx pixel put\n");
	if (x >= 0 && x <= 1920 && y >= 0 && y <= 1080)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
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
	vars->img->img = mlx_new_image(vars->mlx, vars->map->t_s * vars->map->sz_x,
			vars->map->t_s * vars->map->sz_y);
	prnt("mlx get data addr\n");
	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpp,
			&vars->img->line_length, &vars->img->endian);
	// put_player_on_screen(vars);
	// put_walls_on_screen(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
	return (0);
}

// int	main(void)
// {
// 	t_vars		vars;

// 	vars.map = check_map("maps/map1.ber");
// 	prnt("init\n");
// 	// exit(0);
// 	vars.mlx = mlx_init();
// 	prnt("new window\n");
// 	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
// 	prnt("vars.img alloc\n");
// 	vars.img = malloc(sizeof(*(vars.img)));
// 	if (vars.img == NULL)
// 		return (0);
// 	vars.map->t_s = 351;
// 	vars.color = 0x00FF0000;
// 	prnt("new image\n");
// 	vars.img->img = mlx_new_image(vars.mlx, 1920, 1080);
// 	prnt("get data addr\n");
// 	vars.img->addr = mlx_get_data_addr(vars.img->img, &vars.img->bpp,
// 			&vars.img->line_length, &vars.img->endian);
// 	vars.player_pos.x = 1;
// 	vars.player_pos.y = 1;
// 	prnt("mlx mouse hook\n");
// 	mlx_mouse_hook(vars.win, mouse_hook, &vars);
// 	prnt("mlx key hook\n");
// 	mlx_key_hook(vars.win, key_hook, &vars);
// 	prnt("mlx hook\n");
// 	mlx_hook(vars.win, 17, 1L << 17, ft_close, &vars);
// 	prnt("mlx loop hook\n");
// 	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
// 	prnt("mlx looop\n");
// 	mlx_loop(vars.mlx);
// 	return (0);
// }

//	save an array of (90?) images inside vars, make a function to set each to
//	the background color after tile size is set.

// main for testing transparent player
int	main(void)
{
	t_vars	*vars;
	int		ts;
	int		xs;
	int		ys;
	// t_map	*temp_map;

	vars = malloc(sizeof(vars));
	if (vars == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	vars->map = check_map("maps/map1.ber");
	ts = vars->map->t_s;
	xs = vars->map->sz_x;
	ys = vars->map->sz_y;
	printf("map address 1: %p\n", vars->map);
	vars->mlx = mlx_init();
	printf("map address 2: %p\n", vars->map);
	vars->win = mlx_new_window(vars->mlx, ts * xs,
			ts * ys, "so_long");
	printf("map address 3: %p\n", vars->map);
	printf("testing map tilesize: %i\n", vars->map->t_s);
	create_images(vars, ts);
	exit(error(4));
// 	vars->img = malloc(sizeof(*(vars->img)));
// 	vars->img->img = mlx_new_image(vars->mlx, 51, 51);
// 	vars->img->addr = mlx_get_data_addr(vars->img->img, &vars->img->bpp,
// 			&vars->img->line_length, &vars->img->endian);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 0, 0);
// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->img->img, 120, 120);
// 	mlx_loop_hook(vars->mlx, render_next_frame, vars);
// 	mlx_loop(vars->mlx);
}
