/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:18:58 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/17 21:10:45 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "mlx.h"
# include "keys.h"
# include "libft.h"

# define EXIT_2D_ARRAY 2//failed saving map in 2d array
# define EXIT_RECT 3//map not rectangular
# define EXIT_NOT_WALLED 4//map not walled on all edges
# define EXIT_INVALID_CHAR 5//map uses invalid chars (not 10PEC)
# define EXIT_MAP_TOO_SMALL 6//map is so too small to have P, E and C
# define EXIT_NO_PEC 7//not at least one p, e and c
# define EXIT_MAP_TOO_BIG 8//map is too big, tile size would be too small
# define EXIT_MALLOC_FAILED 9//malloc returned NULL

# define RED 0x00FF0000
# define GREEN 0x00FF00
# define TRANSP 0xFF000000

/*
 *	image struct
 *	img.img is mlx_new_image(mlx, x, y);
 *	img.addr is mlx_get_data_addr(img.img, &img.bpp,
 *			&img.line_length, &img.endian);
 */
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_data_list
{
	t_data				*img;
	struct s_data_list	*next;
}	t_data_list;


typedef struct s_coords
{
	int	x;
	int	y;
}	t_coords;

typedef struct s_poslist
{
	t_coords			pos;
	struct s_poslist	*next;
}	t_poslist;

typedef struct s_map
{
	char		*path;
	char		**map;
	int			color;
	size_t		sz_x;
	size_t		sz_y;
	size_t		count_p;
	size_t		count_e;
	size_t		count_c;
	int			t_s;
}	t_map;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_data		*img;
	t_data		*red;
	t_data		*green;
	t_data		*player;
	t_data		*coll;
	t_data		*ex;
	t_data		*wall;
	t_data_list	*colors;
	t_map		*map;
	t_coords	player_pos;
	t_coords	coords;
	t_coords	mouse_pos;
	int			color;
}	t_vars;

/*	MAP STUFF=================================================================*/

void			is_pec(t_map *map, size_t x, size_t y);
void			init_map_values(t_map *map, char *path);
void			set_tile_size(t_map *map);

/*	UTILITIES=================================================================*/

int				error(int err_code);

/*	LIST STUFF================================================================*/

t_data_list		*lstnew(t_data *img);

/*	COLOR MANIPULATION========================================================*/

void			create_images(t_vars *vars, int ts);
void			fill_images(t_vars *vars, int t_s);

int				ft_change_color_rainbow(int *color);
unsigned int	create_trgb(unsigned int t, unsigned int r,
					unsigned int g, unsigned int b);
unsigned int	get_t(unsigned int trgb);
unsigned int	get_r(unsigned int trgb);
unsigned int	get_g(unsigned int trgb);
unsigned int	get_b(unsigned int trgb);

void			my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*	PLAYER STUFF==============================================================*/

void			put_player_on_screen(t_vars *vars);

/*	BACKGROUND STUFF==========================================================*/

t_data_list		*create_background(t_vars *vars);
// void			ft_background_circles(t_vars *vars);
// void			put_walls_on_screen(t_vars *vars);

/*	MOUSE STUFF===============================================================*/

int				mouse_hook(int button, int x, int y, t_vars *vars);//mouseclick
int				mouse_move(int x, int y, t_vars *vars);

/*	KEY STUFF=================================================================*/

int				key_hook(int keycode, t_vars *vars);
int				ft_close(int keycode, t_vars *vars);

/*	CIRCLE STUFF==============================================================*/

void			ft_put_circle(int r, t_data *img, unsigned int color,
					t_coords middle);
void			ft_put_symmetric_circle(t_data *img, t_coords outer, int color,
					t_coords middle);
t_coords		set_coords( int x, int y);

t_map			*check_map(char *path);

void			prnt(char *str);

#endif