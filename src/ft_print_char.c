/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:35:22 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 03:27:34 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "options.h"

int	ft_print_char(t_opt *opt, va_list args)
{
	int	chr;
	int	bytes;

	chr = va_arg(args, int);
	bytes = 0;
	while ((opt->flags & MIN_WIDTH) && opt->min_width-- > 1)
		bytes += write(1, " ", 1);
	bytes += write(1, &chr, 1);
	while ((opt->flags & DASH) && opt->min_width-- > 1)
		bytes += write(1, " ", 1);
	return (bytes);
}
