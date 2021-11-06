/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 22:31:07 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 20:10:55 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	mouse_hook(int button, int x, int y, t_vars *vars)
{
	(void)button;
	ft_put_circle(150, vars->img, ft_change_color_rainbow(&vars->color),
		ft_set_coords(x, y));
	return (-1);
}

/*
 *	inside main:
 */
//mlx_mouse_hook(vars.win, mouse_hook, &vars);