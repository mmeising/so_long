/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:24 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/20 04:04:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_tile(t_vars *vars, char c, int x, int y)
{
	if (c == '1')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->colors_walls->img->img, x, y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall->img, x, y);
	}
	else if (c == 'C')
	{
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->colors_coll->img->img, x, y);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->coll->img, x, y);
	}
	else if (c == 'E')
	{
		if (vars->map->count_c > 0)
			mlx_put_image_to_window(vars->mlx, vars->win, vars->red->img, x, y);
		else if (vars->map->count_c == 0)
		{
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->colors->img->img, x, y);
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

static void	shift_colors(t_vars *vars)
{
	vars->colors_walls = vars->colors_walls->next;
	vars->colors_coll = vars->colors_coll->next;
	vars->colors = vars->colors->next;
}
/*
 *	depending on the map, vars->slow % x can be changed as a difficulty setting
 *	for example on 19x12, x = 20 is hard, x = 30 is much easier
 *	the lower the number the more often enemies move
 */
int	render_next_frame(t_vars *vars)
{
	int	ts;
	int	y;

	ts = vars->map->t_s;
	y = vars->map->sz_y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->blck->img, 0, 0);
	put_tiles_to_img(vars);
	put_player_to_img(vars);
	put_enemies_to_img(vars, vars->map->t_s);
	check_player_on_enemy(vars, vars->map->p_pos.x, vars->map->p_pos.y);
	mlx_string_put(vars->mlx, vars->win, 0, y * ts + 10, RED, "Steps taken:");
	mlx_string_put(vars->mlx, vars->win, 100, y * ts + 10, RED,
		ft_itoa(vars->steps));
	vars->slow++;
	if (vars->slow % 5 == 0)
	{
		shift_colors(vars);
		if (vars->slow % 25 == 0)
		{
			vars->slow = 0;
			enemy_movement(vars);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	*vars;

	if (argc != 2)
		exit(error(EXIT_WRONG_ARGUMENTS));
	vars = malloc(sizeof(*vars));
	if (vars == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	vars->map = check_map(argv[1]);
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map->t_s * vars->map->sz_x + 1,
			vars->map->t_s * vars->map->sz_y + 11, "so_long");
	vars->colors = colors_circular_linked_list(vars, vars->map->t_s);
	init_and_fill_images(vars, vars->map->t_s);
	mlx_loop_hook(vars->mlx, render_next_frame, vars);
	mlx_key_hook(vars->win, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 17, ft_close, &vars);
	mlx_loop(vars->mlx);
}
