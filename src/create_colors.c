/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:43:51 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/16 22:27:25 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data_list	*init_colors(void)
{
	t_data_list	*colors;
	t_data_list	*temp;

	colors = malloc(sizeof(*colors));
	if (colors == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	temp = colors;
	colors->img = malloc(sizeof(*(colors->img)));
	if (colors->img == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	while 
}

t_data_list	*create_colors(t_vars *vars)
{
	t_data_list	*colors;
	t_data_list	*temp;

	colors = init_colors();
	while ()
	return (colors);
}
