/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_colors_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:24:54 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/20 03:47:55 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*set_img_to_square(t_vars *vars, int ts)
{
	t_data	*img;

	img = malloc(sizeof(*(img)));
	if (img == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	img->img = mlx_new_image(vars->mlx, ts, ts);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	fill_square(img, ft_change_color_rainbow(&vars->color), ts);
	return (img);
}

t_data_list	*colors_circular_linked_list(t_vars *vars, int ts)
{
	t_data_list	*colors;
	t_data_list	*last;
	t_data		*img;
	int			i;

	vars->color = 0x00FF0000;
	i = 0;
	while (i < 90)
	{
		img = set_img_to_square(vars, ts);
		colors = lstadd_front(colors, img);
		i++;
		if (i == 30)
			vars->colors_walls = colors;
		else if (i == 60)
			vars->colors_coll = colors;
	}
	last = lst_last(colors);
	last->next = colors;
	return (colors);
}
