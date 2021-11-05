/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:03:17 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/04 20:57:57 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**	returns color with added shade
**	(distance = 0 -> no change; 1 -> dark; 0.5 -> halfway
*/
unsigned int	add_shade(double distance, unsigned int color)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	distance = 1 - distance;
	t = get_t(color);
	r = get_r(color) * distance;
	g = get_g(color) * distance;
	b = get_b(color) * distance;
	return (create_trgb(t, r, g, b));
}

unsigned int	get_opposite(unsigned int color)
{
	unsigned int	t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = get_t(color);
	r = 255 - get_r(color);
	g = 255 - get_g(color);
	b = 255 - get_b(color);
	return (create_trgb(t, r, g, b));
}

/*
 *	steps can be 1, 3, 5, 15, 17, 51, 85, 255
 */
int	ft_change_color_rainbow(int *color)
{
	prnt("change color rainbow\n");
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
// int	main(void)
// {
// 	unsigned int	trgb;

// 	trgb = get_opposite((unsigned int)0x00B2EEFF);
// 	printf("%u trgb\n", trgb);
// 	return (0);
// }
