/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrepeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 18:09:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/15 16:28:19 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrepeat(char const *s, int times)
{
	int		i;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str = ft_calloc(len * times + 1, sizeof (char));
	if (str)
		while (i < times)
			ft_memmove(str + len * i++, s, len);
	return (str);
}
