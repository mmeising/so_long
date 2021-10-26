/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:59:36 by mmeising          #+#    #+#             */
/*   Updated: 2021/10/26 21:44:06 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = str;
	while (i < len)
	{
		*ptr = c;
		i++;
		ptr++;
	}
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

/*
 *	frees buf[fd] and ret in case read fails (error or no new content)
 */
void	*ft_read_fail(char **buf, int fd, char *ret)
{
	free(buf[fd]);
	buf[fd] = NULL;
	free(ret);
	ret = NULL;
	return (NULL);
}
