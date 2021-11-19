/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:10:46 by mmeising          #+#    #+#             */
/*   Updated: 2021/11/19 03:09:25 by mmeising         ###   ########.fr       */
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
		exit(error(EXIT_MALLOC_FAILED));
	ele->img = img;
	ele->next = NULL;
	return (ele);
}

/*
 *	Creates new list element with content sent as pos and if the list lst does
 *	not yet exist, makes that element start of the list. Otherwise adds the
 *	element to the front of the list lst.
 */
t_data_list	*lstadd_front(t_data_list **lst, t_data *img)
{
	t_data_list	*ele;

	ele = (t_data_list *)malloc(sizeof(*ele));
	if (ele == NULL)
		return (NULL);
	ele->img = img;
	if (lst)
		ele->next = *lst;
	else
		ele->next = NULL;
	*lst = ele;
	return (ele);
}