/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:22:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/30 15:23:25 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, char const *src)
{
	size_t	i;

	i = 0;
	while (*src)
		dst[i++] = *src++;
	dst[i] = 0;
	return (dst);
}
