/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmeising <mmeising@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:59:30 by mmeising          #+#    #+#             */
/*   Updated: 2021/09/29 12:48:27 by mmeising         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_main(char **buf, char *ret, int fd, int *n);
int		ft_finished_buf(char **buf, int fd, int *r, int *read_flag);
char	*ft_realloc(char *ret_old, int *n);
char	*ft_rest(char **buf, int fd, int *read_flag);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_read_fail(char **buf, int fd, char *ret);

#endif