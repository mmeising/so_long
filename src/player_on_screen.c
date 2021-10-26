/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:01:25 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/26 22:16:50 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_player_on_screen(t_vars *vars)
{
	prnt("put player on screen\n");
	int	i;
	int	r;

	i = 0;
	r = vars->map.size_tile / 2;
	ft_put_circle(r - i, vars->img, ft_change_color_rainbow(&vars->color),
				ft_set_coords(vars->player_pos.x + i, vars->player_pos.y + i));
	while (i < r)
	{
		if ((r - i) % 4 == 0)
		{
			ft_put_circle(r - i, vars->img, vars->color,
				ft_set_coords(vars->player_pos.x + i, vars->player_pos.y + i));
		}
		if (i % 5 == 0)
			ft_change_color_rainbow(&vars->color);
		i++;
	}
}
