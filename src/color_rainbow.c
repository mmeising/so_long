/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:03:17 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 22:08:01 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 *	steps can be 1, 3, 5, 15, 17, 51, 85, 255
 */
int	ft_change_color_rainbow(int *color)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	int				steps;

	steps = 17;
	t = get_t(*color);
	r = get_r(*color);
	g = get_g(*color);
	b = get_b(*color);
	if (r == 255 && g < 255 && b == 0)
		g += steps;
	else if (g == 255 && r > 0 && b == 0)
		r -= steps;
	else if (g == 255 && b < 255 && r == 0)
		b += steps;
	else if (b == 255 && g > 0 && r == 0)
		g -= steps;
	else if (b == 255 && r < 255 && g == 0)
		r += steps;
	else if (r == 255 && b > 0 && g == 0)
		b -= steps;
	*color = create_trgb(t, r, g, b);
	return (*color);
}
