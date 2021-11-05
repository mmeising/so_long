/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:32:52 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/04 23:54:48 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	ft_is_movable(int keycode, t_vars *vars)
// {
	
// }

/*
 *	first argument is keycode of the pressed key
 *	second argument is the last argument passed in mlx_key_hook
 */
int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_W)
	{
		vars->player_pos.y -= vars->map->t_s + 1;
	}
	if (keycode == KEY_A)
	{
		vars->player_pos.x -= vars->map->t_s + 1;
	}
	if (keycode == KEY_S)
	{
		vars->player_pos.y += vars->map->t_s + 1;
	}
	if (keycode == KEY_D)
	{
		vars->player_pos.x += vars->map->t_s + 1;
	}
	if (keycode == KEY_ESCAPE)
		ft_close(keycode, vars);
	return (-1);
}