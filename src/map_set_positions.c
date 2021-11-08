/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_positions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:24:56 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/08 18:21:21 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 *	creates new t_poslist pointer, sets pos as its content and returns it
 */
t_poslist	*lstnew(t_coords pos)
{
	t_poslist	*ele;

	ele = (t_poslist *)malloc(sizeof(*ele));
	if (ele == NULL)
		return (NULL);
	ele->pos = pos;
	ele->next = NULL;
	return (ele);
}

/*
 *	Creates new list element with content sent as pos and if the list lst does
 *	not yet exist, makes that element start of the list. Otherwise adds the
 *	element to the front of the list lst.
 */
t_poslist	*lstadd_front(t_poslist **lst, t_coords pos)
{
	t_poslist	*ele;

	ele = (t_poslist *)malloc(sizeof(*ele));
	if (ele == NULL)
		return (NULL);
	ele->pos = pos;
	if (lst)
		ele->next = *lst;
	else
		ele->next = NULL;
	*lst = ele;
	return (ele);
	// new->next = *lst;
	// *lst = new;
}

// void	init_lists(t_map *map)
// {
// 	map->list_p =
// }

void	is_pec1(t_map *map, size_t x, size_t y)
{
	if (ft_in_set(map->map[y][x], "P"))
	{
		map->count_p++;
		map->list_p = lstadd_front(&map->list_p, ft_set_coords(x, y));
	}
	else if (ft_in_set(map->map[y][x], "E"))
	{
		map->count_e++;
		map->list_e = lstadd_front(&map->list_e, ft_set_coords(x, y));
	}
	else if (ft_in_set(map->map[y][x], "C"))
	{
		map->count_c++;
		map->list_c = lstadd_front(&map->list_c, ft_set_coords(x, y));
	}
	else if (ft_in_set(map->map[y][x], "1"))
	{
		map->list_1 = lstadd_front(&map->list_1, ft_set_coords(x, y));
	}
	// init_lists(map);
}