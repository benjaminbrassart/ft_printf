/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 10:04:05 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/22 10:40:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void const *src, size_t len)
{
	unsigned char		*d;
	unsigned char const	*s;

	if (src == NULL && dst == NULL)
		return (NULL);
	if (src > dst)
		return (ft_memcpy(dst, src, len));
	d = dst;
	s = src;
	while (len--)
		d[len] = s[len];
	return (dst);
}
