/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rawmemchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:18:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/11 01:31:21 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_rawmemchr(void const *s, int c)
{
	unsigned char const	*b;
	unsigned char		ch;

	b = s;
	ch = c;
	while (*b)
	{
		if (*b == ch)
			return ((void *)b);
		++b;
	}
	return (NULL);
}
