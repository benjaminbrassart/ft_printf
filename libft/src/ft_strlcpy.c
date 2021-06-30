/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:04:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/25 17:16:06 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char const *src, size_t dstsize)
{
	size_t	len;
	int		nt;

	if (!(dst && src))
		return (0);
	len = ft_strlen(src);
	nt = (dstsize > 0);
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	if (nt)
		*dst = 0;
	return (len);
}
