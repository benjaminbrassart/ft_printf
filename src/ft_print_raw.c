/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_raw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 18:51:45 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/05 18:57:22 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "options.h"
#include "print_functions.h"

int	ft_print_raw(t_opt *opt, int chr)
{
	int	bytes;

	bytes = 0;
	while ((opt->flags & ZERO) && opt->min_width-- > 1)
		bytes += write(1, "0", 1);
	while ((opt->flags & MIN_WIDTH) && opt->min_width-- > 1)
		bytes += write(1, " ", 1);
	bytes += write(1, &chr, 1);
	while ((opt->flags & DASH) && opt->min_width-- > 1)
		bytes += write(1, " ", 1);
	return (bytes);
}
