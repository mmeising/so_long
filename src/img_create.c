/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:43:51 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 19:10:26 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_img_addr(t_vars *vars)
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
}

/*
 *	the set images (background colors red and green,
 *	transparent player, collectible, exit and wall) are malloc'd and configured
 *	as needed with mlx functions
 */
void	init_images(t_vars *vars, int ts)
{
	vars->blck = malloc(sizeof(*(vars->blck)));
	vars->red = malloc(sizeof(*(vars->red)));
	vars->green = malloc(sizeof(*(vars->green)));
	vars->player = malloc(sizeof(*(vars->player)));
	vars->coll = malloc(sizeof(*(vars->coll)));
	vars->ex = malloc(sizeof(*(vars->ex)));
	vars->wall = malloc(sizeof(*(vars->wall)));
	if (!(vars->blck && vars->red && vars->green && vars->player && vars->coll
			&& vars->ex && vars->wall))
		exit(error(EXIT_MALLOC_FAILED));
	vars->blck->img = mlx_new_image(vars->mlx, vars->map->t_s * vars->map->sz_x,
			vars->map->t_s * vars->map->sz_y);
	vars->red->img = mlx_new_image(vars->mlx, ts, ts);
	vars->green->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	vars->player->img = mlx_new_image(vars->mlx, vars->map->t_s,
			vars->map->t_s);
	vars->coll->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	vars->ex->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	vars->wall->img = mlx_new_image(vars->mlx, vars->map->t_s, vars->map->t_s);
	init_img_addr(vars);
}
