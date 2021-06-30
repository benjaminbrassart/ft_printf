/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 16:20:21 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/30 16:23:35 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(void const *s, int c, size_t n)
{
	unsigned char const	*b;
	unsigned char		ch;

	b = s;
	ch = c;
	while (n--)
		if (b[n] == ch)
			return ((void *)b + n);
	return (NULL);
}
