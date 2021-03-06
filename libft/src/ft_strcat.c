/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:23:31 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/30 15:24:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, char const *src)
{
	size_t	i;

	i = 0;
	while (dst[i])
		++i;
	while (*src)
		dst[i++] = *src++;
	dst[i] = 0;
	return (dst);
}
