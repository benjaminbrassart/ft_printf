/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 04:14:06 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 04:20:57 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "options.h"
#include "libft.h"

int	ft_print_string(t_opt *opt, va_list args)
{
	char const	*s;
	size_t		len;
	int			bytes;

	s = va_arg(args, char const *);
	if (s == NULL)
		s = "(null)";
	if (opt->flags & PRECISION)
		len = ft_strnlen(s, opt->precision);
	else
		len = ft_strlen(s);
	bytes = 0;
	while ((opt->flags & MIN_WIDTH) && opt->min_width-- > (int)len)
		bytes += write(1, " ", 1);
	bytes += write(1, s, len);
	while ((opt->flags & DASH) && opt->min_width-- > (int)len)
		bytes += write(1, " ", 1);
	return (bytes);
}
