/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 00:00:19 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 12:04:49 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"
#include "options.h"
#include "print_functions.h"

static int	exec_format(char const **format, va_list args)
{
	int			bytes;
	t_opt		*opt;
	t_printer	printer;

	opt = ft_parse_options(format, args);
	printer = ft_get_printer(**format);
	if (printer.fn)
		bytes = printer.fn(opt, args);
	else
		bytes = write(1, *format, 1);
	free(opt);
	return (bytes);
}

int	ft_printf(char const *format, ...)
{
	va_list		args;
	int			bytes;

	bytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			++format;
			bytes += exec_format(&format, args);
		}
		else
			bytes += write(1, format, 1);
		++format;
	}
	va_end(args);
	return (bytes);
}
