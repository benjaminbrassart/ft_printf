/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 05:25:52 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 01:31:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

static t_gnl_fd_list	*get_or_add_fd(t_gnl_fd_list **head, int fd)
{
	t_gnl_fd_list	*list;

	list = *head;
	while (list)
	{
		if (list->fd == fd)
			return (list);
		list = list->next;
	}
	list = malloc(sizeof (*list));
	if (list)
	{
		list->fd = fd;
		list->next = *head;
		ft_memset(list->rest, 0, BUFFER_SIZE + 1);
		*head = list;
	}
	return (list);
}

static int	remove_fd(t_gnl_fd_list **head, int fd, int re)
{
	t_gnl_fd_list	*prev;
	t_gnl_fd_list	*list;

	prev = NULL;
	list = *head;
	while (list)
	{
		if (list->fd == fd)
		{
			if (prev)
				prev->next = list->next;
			else
				*head = list->next;
			free(list);
			break ;
		}
		prev = list;
		list = list->next;
	}
	return (re);
}

static void	join_line(char **line, char buffer[BUFFER_SIZE + 1], size_t n)
{
	size_t	i;
	char	*s;

	i = 0;
	while (*line && (*line)[i])
		++i;
	s = malloc(i + n + 1);
	if (s)
	{
		ft_memmove(s, *line, i);
		ft_memmove(s + i, buffer, n);
		s[i + n] = 0;
		free(*line);
		*line = s;
	}
}

static int	copy_until_line_break(char **line, char buffer[BUFFER_SIZE + 1],
		char rest[BUFFER_SIZE + 1])
{
	int	i;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	join_line(line, buffer, i);
	ft_memset(rest, 0, BUFFER_SIZE + 1);
	if (buffer[i])
		ft_strcpy(rest, buffer + i + 1);
	return (!!buffer[i]);
}

int	get_next_line(int fd, char **line)
{
	static t_gnl_fd_list	*head = NULL;
	t_gnl_fd_list			*list;
	char					buffer[BUFFER_SIZE + 1];
	int						bytes;

	if (BUFFER_SIZE < 1)
		return (-1);
	list = get_or_add_fd(&head, fd);
	if (list->rest[0])
		if (copy_until_line_break(line, list->rest, list->rest))
			return (1);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, ft_memset(buffer, 0, BUFFER_SIZE + 1), BUFFER_SIZE);
		if (bytes > 0 && copy_until_line_break(line, buffer, list->rest))
			return (1);
	}
	return (remove_fd(&head, fd, bytes));
}
