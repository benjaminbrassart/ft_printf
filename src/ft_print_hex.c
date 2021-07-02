/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 04:54:42 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 07:20:26 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft.h"
#include "options.h"
#include "print_functions.h"

static int	ft_hex_size(unsigned int n)
{
	int	i;

	i = 1;
	while (n / 16)
	{
		++i;
		n /= 16;
	}
	return (i);
}

static void	ft_puthex(unsigned int n, int b, int (*lf)(int))
{
	if (--b > 0)
		ft_puthex(n / 16, b, lf);
	ft_putchar(lf(BASE_HEX[n % 16]));
}

static int	ft_print_hex(t_opt *opt, unsigned int n, int (*lf)(int))
{
	int	bytes;
	int	digits;

	digits = ft_hex_size(n);
	if (digits < opt->precision)
		digits = opt->precision;
	if (opt->flags & PRECISION)
		opt->flags &= ~ZERO;
	bytes = digits;
	if (opt->flags & PRECISION && opt->precision == 0 && n == 0)
		bytes = 0;
	while ((opt->flags & ZERO) && opt->min_width > bytes)
		bytes += write(1, "0", 1);
	while ((opt->flags & MIN_WIDTH) && opt->min_width > bytes)
		bytes += write(1, " ", 1);
	if (!(opt->flags & PRECISION && opt->precision == 0 && n == 0))
		ft_puthex(n, digits, lf);
	while ((opt->flags & DASH) && opt->min_width > bytes)
		bytes += write(1, " ", 1);
	return (bytes);
}

int	ft_print_hex_low(t_opt *opt, va_list args)
{
	return (ft_print_hex(opt, va_arg(args, unsigned int), ft_tolower));
}

int	ft_print_hex_up(t_opt *opt, va_list args)
{
	return (ft_print_hex(opt, va_arg(args, unsigned int), ft_toupper));
}
