/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 19:01:25 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/05 01:49:44 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//	2 images. one is full tile size in one colour, set with memset.
//	second image only gets created oncein the beginning with tile size,
//	is transparent on circle's pixels. print it over coloured image
//	-> colored circle. 
void	put_player_on_screen(t_vars *vars)
{
	int	i;
	int	r;
	int	ts;

	prnt("put player on screen\n");
	i = 4;
	ts = vars->map->t_s;
	r = ts / 2;
	ft_put_circle(r - i, vars, ft_change_color_rainbow(&vars->color),
		ft_set_coords(vars->player_pos.x + r + i, vars->player_pos.y + r + i));
	while (i < r)
	{
		if ((r - i) % 2 == 0)
		{
			ft_put_circle(r - i, vars, vars->color,
				ft_set_coords(vars->player_pos.x + i, vars->player_pos.y + i));
		}
		if (i % r == 0)
			ft_change_color_rainbow(&vars->color);
		i++;
	}
}
