/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:34:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/22 10:39:42 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *s, int c, size_t n)
{
	unsigned char const	*b;
	unsigned char		ch;
	size_t				i;

	b = s;
	ch = c;
	i = 0;
	while (i < n)
	{
		if (b[i] == ch)
			return ((void *)b + i);
		i++;
	}
	return (NULL);
}
