/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:23:34 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/01 05:41:54 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

typedef struct s_gnl_fd_list
{
	int						fd;
	char					rest[BUFFER_SIZE + 1];
	struct s_gnl_fd_list	*next;
}	t_gnl_fd_list;

int	get_next_line(int fd, char **line)
	__attribute__((nonnull(2)));

#endif
