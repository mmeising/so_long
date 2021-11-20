/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 02:09:08 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/20 02:42:42 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//enemy_movable function to check if new pos is '0' and not already
//an enemy position -> return 1, otherwise returns 0

int	enemy_movable(t_vars *vars, int x, int y)
{
	int	e0_x;
	int	e0_y;
	int	e1_x;
	int	e1_y;

	e0_x = vars->map->enemy_p_0.x;
	e0_y = vars->map->enemy_p_0.y;
	e1_x = vars->map->enemy_p_1.x;
	e1_y = vars->map->enemy_p_1.y;
	if ((x == e0_x && y == e0_y) || (x == e1_x && y == e1_y))
		return (0);
	if (vars->map->map[y][x] == '0')
		return (1);
	else
		return (0);
}

void	approach_x(t_vars *vars, t_coords *enemy, t_coords *player)
{
	if (player->x < enemy->x && enemy_movable(vars, enemy->x - 1, enemy->y))
	{
		enemy->x--;
	}
	if (player->x > enemy->x && enemy_movable(vars, enemy->x + 1, enemy->y))
	{
		enemy->x++;
	}
}

void	approach_y(t_vars *vars, t_coords *enemy, t_coords *player)
{
	if (player->y < enemy->y && enemy_movable(vars, enemy->x, enemy->y - 1))
	{
		enemy->y--;
	}
	if (player->y > enemy->y && enemy_movable(vars, enemy->x, enemy->y + 1))
	{
		enemy->y++;
	}
}

/*
 *	rand() % 5 sets rng to random value between 0 and 4.
 */
void	enemy_movement(t_vars *vars)
{
	int		rng;

	rng = rand() % 5;
	if (rng == 1)
	{
		approach_x(vars, &vars->map->enemy_p_0, &vars->map->p_pos);
	}
	else if (rng == 2)
	{
		approach_y(vars, &vars->map->enemy_p_0, &vars->map->p_pos);
	}
	else if (rng == 3)
	{
		approach_x(vars, &vars->map->enemy_p_1, &vars->map->p_pos);
	}
	else if (rng == 4)
	{
		approach_y(vars, &vars->map->enemy_p_1, &vars->map->p_pos);
	}
}
