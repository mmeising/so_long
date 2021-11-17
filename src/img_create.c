/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:43:51 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/17 20:58:51 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

	// t_data_list	*colors;

	// colors = malloc(sizeof(*colors));
	// if (colors == NULL)
	// 	exit(error(EXIT_MALLOC_FAILED));
	// colors->img = malloc(sizeof(*(colors->img)));
	// if (colors->img == NULL)
	// 	exit(error(EXIT_MALLOC_FAILED));

// static void	init_img_addr(t_vars *vars)
// {
// 	vars->red->addr = mlx_get_data_addr(vars->red->img, &vars->red->bpp,
// 			&vars->red->line_length, &vars->red->endian);
// 	vars->green->addr = mlx_get_data_addr(vars->green->img, &vars->green->bpp,
// 			&vars->green->line_length, &vars->green->endian);
// 	vars->player->addr = mlx_get_data_addr(vars->player->img,
// 			&vars->player->bpp, &vars->player->line_length,
// 			&vars->player->endian);
// 	vars->coll->addr = mlx_get_data_addr(vars->coll->img, &vars->coll->bpp,
// 			&vars->coll->line_length, &vars->coll->endian);
// 	vars->ex->addr = mlx_get_data_addr(vars->ex->img, &vars->ex->bpp,
// 			&vars->ex->line_length, &vars->ex->endian);
// 	vars->wall->addr = mlx_get_data_addr(vars->wall->img, &vars->wall->bpp,
// 			&vars->wall->line_length, &vars->wall->endian);
// }


/*
 *	the set images (background colors red and green,
 *	transparent player, collectible, exit and wall) are malloc'd and configured
 *	as needed with mlx functions
 */
static void	init_images(t_vars *vars, int ts)
{
	vars->red = malloc(sizeof(*(vars->red)));
	printf("right after malloc\n");
	// vars->green = malloc(sizeof(*(vars->green)));
	// vars->player = malloc(sizeof(*(vars->player)));
	// vars->coll = malloc(sizeof(*(vars->coll)));
	// vars->ex = malloc(sizeof(*(vars->ex)));
	// vars->wall = malloc(sizeof(*(vars->wall)));
	// if (!(vars->red /*&& vars->green && vars->player && vars->coll && vars->ex
			// && vars->wall*/))
	printf("tile size: %i\n", ts);
	if (vars->red == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	vars->red->img = mlx_new_image(vars->mlx, ts, ts);
	// vars->green->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	// vars->player->img = mlx_new_image(vars->mlx, vars->map->t_s,
	// 		vars->map->t_s);
	// vars->coll->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	// vars->ex->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	// vars->wall->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	printf("after address stuff\n");
	// init_img_addr(vars);
}

void	create_images(t_vars *vars, int ts)
{
	// t_data_list	*colors;
	// t_data_list	*temp;
	// int			i;

	init_images(vars, ts);
	printf("test\n");
	// fill_images(vars, vars->map->t_s);
	// temp = colors;
	// vars->color = 0x00FF0000;
	// i = 0;
	// while (i < 90)
	// {
	// 	i++;
	// }
}
