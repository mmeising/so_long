/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:59:32 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/26 17:59:58 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_background_circles(t_vars *vars)
{
	static int	r;
	int	t;
	int	trgb;

	r = 10;
	if (r < 51)
		r++;
	else
		r = 1;
	t = 250;//get_t(vars->color);
	// if (t < 254)
	// 	t++;
	// else
	// 	t = 150;
	trgb = (vars->color & 0x00FFFFFF) | t << 24;
	ft_put_circle(r, vars->img, trgb, ft_set_coords(500, 400));
}