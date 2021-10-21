/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_get_trgb.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:27:03 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/21 19:56:16 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
 *	bitshifts to the left, then uses bitwise OR to add all in one unsigned
 *	integer e.g.:
 *	(each byte represented as 2 digits in hexadecimal for simplicity's sake)
 *	00000000 t
 *	00FF0000 r
 *	0000FF00 g
 *	0000000F b
 *	00FFFF0F trgb 
 */
unsigned int	create_trgb(unsigned int t, unsigned int r,
							unsigned int g, unsigned int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/*
 *	returns 0-255 value of transparency out of color
 */
unsigned int	get_t(unsigned int trgb)
{
	return ((trgb & (0xFF << 24)) >> 24);
}

/*
 *	returns 0-255 value of red out of color
 */
unsigned int	get_r(unsigned int trgb)
{
	return ((trgb & (0xFF << 16)) >> 16);
}

/*
 *	returns 0-255 value of green out of color
 */
unsigned int	get_g(unsigned int trgb)
{
	return ((trgb & (0xFF << 8)) >> 8);
}

/*
 *	returns 0-255 value of blue out of color
 */
unsigned int	get_b(unsigned int trgb)
{
	return (trgb & 0xFF);
}
