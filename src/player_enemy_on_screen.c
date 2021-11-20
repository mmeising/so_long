/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_enemy_on_screen.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:01:25 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/20 02:05:48 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_to_img(t_vars *vars)
{
	int	ts;
	int	x;
	int	y;

	ts = vars->map->t_s;
	x = vars->map->p_pos.x;
	y = vars->map->p_pos.y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->colors->img->img,
		x * ts, y * ts);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->player->img,
		x * ts, y * ts);
}

void	put_enemies_to_img(t_vars *vars, int ts)
{
	int	e0_x;
	int	e0_y;
	int	e1_x;
	int	e1_y;

	e0_x = vars->map->enemy_p_0.x;
	e0_y = vars->map->enemy_p_0.y;
	e1_x = vars->map->enemy_p_1.x;
	e1_y = vars->map->enemy_p_1.y;
	if (e0_x && e0_y)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->red->img,
			e0_x * ts, e0_y * ts);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy->img,
			e0_x * ts, e0_y * ts);
	}
	if (e1_x && e1_y)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->red->img,
			e1_x * ts, e1_y * ts);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->enemy->img,
			e1_x * ts, e1_y * ts);
	}
}

void	check_player_on_enemy(t_vars *vars, int p_x, int p_y)
{
	int	e0_x;
	int	e0_y;
	int	e1_x;
	int	e1_y;

	e0_x = vars->map->enemy_p_0.x;
	e0_y = vars->map->enemy_p_0.y;
	e1_x = vars->map->enemy_p_1.x;
	e1_y = vars->map->enemy_p_1.y;
	if ((p_x == e0_x && p_y == e0_y) || (p_x == e1_x && p_y == e1_y))
	{
		printf("Game Over!\nPlayer touched the enemy\n");
		exit(EXIT_TOUCHED_ENEMY);
	}
}
