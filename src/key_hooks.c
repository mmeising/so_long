/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:32:52 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 03:50:03 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void finish_game(int steps)
{
	printf("%i steps taken\n", ++steps);
	printf("Congratulations!\nYou completed the game with %i steps!\n", steps);
	exit(0);
}

static int	is_movable(t_vars *vars, int x, int y)
{
	char	c;

	c = vars->map->map[y][x];
	if (c == '0')
	{
		return (1);
	}
	else if (c == 'C')
	{
		vars->map->map[y][x] = '0';
		vars->map->count_c -= 1;
		return (1);
	}
	else if (c == 'E' && vars->map->count_c == 0)
	{
		finish_game(vars->steps);
		return (1);
	}
	else
		return (0);
}

/*
 *	first argument is key of the pressed key
 *	second argument is the last argument passed in mlx_key_hook
 */
int	key_hook(int key, t_vars *vars)
{
	t_coords	*pp;

	pp = &vars->map->p_pos;
	if (key == KEY_W && is_movable(vars, pp->x, pp->y - 1))
	{
		printf("%i steps taken\n", ++vars->steps);
		pp->y -= 1;
	}
	if (key == KEY_A && is_movable(vars, pp->x - 1, pp->y))
	{
		printf("%i steps taken\n", ++vars->steps);
		vars->map->p_pos.x -= 1;
	}
	if (key == KEY_S && is_movable(vars, pp->x, pp->y + 1))
	{
		printf("%i steps taken\n", ++vars->steps);
		vars->map->p_pos.y += 1;
	}
	if (key == KEY_D && is_movable(vars, pp->x + 1, pp->y))
	{
		printf("%i steps taken\n", ++vars->steps);
		vars->map->p_pos.x += 1;
	}
	if (key == KEY_ESCAPE)
		ft_close(key, vars);
	return (-1);
}
