/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 23:32:52 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/26 21:54:16 by mmeising         ###   ########.fr       */
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
		vars->player_pos.y -= vars->map.size_tile;
	}
	if (keycode == KEY_A)
	{
		vars->player_pos.x -= vars->map.size_tile;
	}
	if (keycode == KEY_S)
	{
		vars->player_pos.y += vars->map.size_tile;
	}
	if (keycode == KEY_D)
	{
		vars->player_pos.x += vars->map.size_tile;
	}
	if (keycode == KEY_ESCAPE)
		ft_close(keycode, vars);
	return (-1);
}