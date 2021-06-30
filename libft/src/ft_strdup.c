/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 09:52:27 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/29 12:17:38 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s)
{
	size_t	n;
	char	*str;

	n = ft_strlen(s);
	str = (char *)ft_calloc(n + 1, sizeof (char));
	if (str)
		ft_memcpy(str, s, n);
	return (str);
}
