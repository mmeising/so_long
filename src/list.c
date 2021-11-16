/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:10:46 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/16 22:30:05 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
 *	creates new t_data_list pointer, sets img as its content and returns it
 */
t_data_list	*lstnew(t_data *img)
{
	t_data_list	*ele;

	ele = (t_data_list *)malloc(sizeof(*ele));
	if (ele == NULL)
		return (NULL);
	ele->img = img;
	ele->next = NULL;
	return (ele);
}

/*
 *	Creates new list element with content sent as pos and if the list lst does
 *	not yet exist, makes that element start of the list. Otherwise adds the
 *	element to the front of the list lst.
 */
// t_poslist	*lstadd_front(t_poslist **lst, t_coords pos)
// {
// 	t_poslist	*ele;

// 	ele = (t_poslist *)malloc(sizeof(*ele));
// 	if (ele == NULL)
// 		return (NULL);
// 	ele->pos = pos;
// 	if (lst)
// 		ele->next = *lst;
// 	else
// 		ele->next = NULL;
// 	*lst = ele;
// 	return (ele);
// }