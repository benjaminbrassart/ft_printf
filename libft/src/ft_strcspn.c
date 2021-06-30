/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 03:10:01 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/11 03:11:59 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(char const *s, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strchr(set, s[i]))
		++i;
	return (i);
}
