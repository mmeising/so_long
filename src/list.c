/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:10:46 by mmeising          #+#    #+#             */
/*   Updated: 2021/12/05 17:07:04 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data_list	*lst_last(t_data_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
 *	Creates new list element with content sent as img and if the list lst does
 *	not yet exist, makes that element start of the list. Otherwise adds the
 *	element to the front of the list lst.
 */
t_data_list	*lstadd_front(t_data_list *lst, t_data *img)
{
	t_data_list	*ele;

	ele = (t_data_list *)malloc(sizeof(*ele));
	if (ele == NULL)
		exit(error(EXIT_MALLOC_FAILED));
	ele->img = img;
	if (lst)
		ele->next = lst;
	else
		ele->next = NULL;
	lst = ele;
	return (ele);
}
