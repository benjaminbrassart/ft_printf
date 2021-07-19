/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:27:02 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/19 22:54:27 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_patoi(char const **s)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while (ft_isspace(**s))
		++(*s);
	if (**s == '-' || **s == '+')
		if (*(*s)++ == '-')
			sign = -1;
	while (ft_isdigit(**s))
		i = i * 10 + *(*s)++ - '0';
	return (i * sign);
}
