/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:01:25 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 20:28:15 by mmeising         ###   ########.fr       */
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
