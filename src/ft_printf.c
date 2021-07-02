/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:00:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 03:21:29 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "options.h"
#include "print_functions.h"

int	ft_printf(char const *format, ...)
{
	va_list		args;
	t_opt		*opt;
	t_printer	printer;
	int			bytes;

	bytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			opt = ft_parse_options(&format, args);
			printer = ft_get_printer(*format);
			if (printer.fn)
				bytes += printer.fn(opt, args);
			else
				bytes += write(1, format, 1);
			free(opt);
		}
		else
			bytes += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (bytes);
}
