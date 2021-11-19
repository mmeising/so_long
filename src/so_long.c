/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:24 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 04:15:17 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keycode, t_vars *vars)
{
	(void)vars;
	(void)keycode;
	exit(0);
	return (0);
}

static void	put_tile(t_vars *vars, char c, int x, int y)
{
	if (c == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->red->img, x, y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, x, y);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->green->img, x, y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coll->img, x, y);
	}
	else if (c == 'E')
	{
		if (vars->map->count_c > 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->red->img, x, y);
		else if (vars->map->count_c == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->green->img,
					x, y);
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->ex->img, x, y);
	}
}

static void	put_tiles_to_img(t_vars *vars)
{
	int	ts;
	int	x;
	int	y;

	ts = vars->map->t_s;
	y = 0;
	while (vars->map->map[y])
	{
		x = 0;
		while (vars->map->map[y][x])
		{
			put_tile(vars, vars->map->map[y][x], x * ts, y * ts);
			x++;
		}
		y++;
	}
}

int	render_next_frame(t_vars *vars)
{
	(void)vars;
	prnt("render next frame\n");
	mlx_put_image_to_window(vars->mlx, vars->win, vars->blck->img, 0, 0);
	put_tiles_to_img(vars);
	put_player_to_img(vars);
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

int	main(void)
{
	t_vars	*vars;

	vars = malloc(sizeof(*vars));
	if (vars == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	vars->map = check_map("maps/map_xxl.ber");
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map->t_s * vars->map->sz_x + 1,
			vars->map->t_s * vars->map->sz_y, "so_long");
	// vars->colors = colors_circular_linked_list(vars, RED, vars->map->t_s);
	init_images(vars, vars->map->t_s);
	fill_images(vars, vars->map->t_s);
	vars->steps = 0;
	
	put_tiles_to_img(vars);
	put_player_to_img(vars);

	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close, &vars);
	mlx_loop(vars->mlx);
}
