/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:43:51 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/20 03:03:29 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_img_addr(t_vars *vars)
{
	vars->blck->addr = mlx_get_data_addr(vars->blck->img, &vars->blck->bpp,
			&vars->blck->line_length, &vars->blck->endian);
	vars->red->addr = mlx_get_data_addr(vars->red->img, &vars->red->bpp,
			&vars->red->line_length, &vars->red->endian);
	vars->green->addr = mlx_get_data_addr(vars->green->img, &vars->green->bpp,
			&vars->green->line_length, &vars->green->endian);
	vars->player->addr = mlx_get_data_addr(vars->player->img,
			&vars->player->bpp, &vars->player->line_length,
			&vars->player->endian);
	vars->coll->addr = mlx_get_data_addr(vars->coll->img, &vars->coll->bpp,
			&vars->coll->line_length, &vars->coll->endian);
	vars->ex->addr = mlx_get_data_addr(vars->ex->img, &vars->ex->bpp,
			&vars->ex->line_length, &vars->ex->endian);
	vars->wall->addr = mlx_get_data_addr(vars->wall->img, &vars->wall->bpp,
			&vars->wall->line_length, &vars->wall->endian);
	vars->enemy->addr = mlx_get_data_addr(vars->enemy->img, &vars->enemy->bpp,
			&vars->enemy->line_length, &vars->enemy->endian);
}

/*
 *	the set images (background colors red and green,
 *	transparent player, collectible, exit and wall) are malloc'd and configured
 *	as needed with mlx functions
 */
void	init_images(t_vars *vars, int ts, int x, int y)
{
	vars->blck = malloc(sizeof(*(vars->blck)));
	vars->red = malloc(sizeof(*(vars->red)));
	vars->green = malloc(sizeof(*(vars->green)));
	vars->player = malloc(sizeof(*(vars->player)));
	vars->coll = malloc(sizeof(*(vars->coll)));
	vars->ex = malloc(sizeof(*(vars->ex)));
	vars->wall = malloc(sizeof(*(vars->wall)));
	vars->enemy = malloc(sizeof(*(vars->enemy)));
	if (!(vars->blck && vars->red && vars->green && vars->player && vars->coll
			&& vars->ex && vars->wall && vars->enemy))
		exit(error(EXIT_MALLOC_FAILED));
	vars->blck->img = mlx_new_image(vars->mlx, ts * x, ts * y + 11);
	vars->red->img = mlx_new_image(vars->mlx, ts, ts);
	vars->green->img = mlx_new_image(vars->mlx, ts, ts);
	vars->player->img = mlx_new_image(vars->mlx, ts, ts);
	vars->coll->img = mlx_new_image(vars->mlx, ts, ts);
	vars->ex->img = mlx_new_image(vars->mlx, ts, ts);
	vars->wall->img = mlx_new_image(vars->mlx, ts, ts);
	vars->enemy->img = mlx_new_image(vars->mlx, ts, ts);
	init_img_addr(vars);
}
