/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 15:30:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/05/30 15:32:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	size_t	len;
	char	*str;

	len = ft_strnlen(s, n);
	str = ft_calloc(len + 1, sizeof (char));
	if (str)
		ft_strncpy(str, s, n);
	return (str);
}
