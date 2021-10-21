/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:58 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/21 22:05:56 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include "../mlx/mlx.h"
# include "keys.h"

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_coords	*coords;;
}	t_vars;

unsigned int	create_trgb(unsigned int t, unsigned int r,
					unsigned int g, unsigned int b);
unsigned int	get_t(unsigned int trgb);
unsigned int	get_r(unsigned int trgb);
unsigned int	get_g(unsigned int trgb);
unsigned int	get_b(unsigned int trgb);

#endif