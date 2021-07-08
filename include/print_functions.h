/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:41:27 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/08 11:46:52 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTIONS_H
# define PRINT_FUNCTIONS_H

# include <stdarg.h>
# include <stdlib.h>
# include "options.h"

typedef struct s_printer
{
	int	chr;
	int	(*fn)(t_opt *, va_list);
}	t_printer;

void					ft_putstr_fn(char const *s, int (*fn)(int));

int						ft_print_char(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_string(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_pointer(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_int(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_uint(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_hex_low(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_hex_up(t_opt *opt, va_list args)
						__attribute__((nonnull(1)));

int						ft_print_raw(t_opt *opt, int chr)
						__attribute__((nonnull(1)));

static t_printer const	g_printers[] = {
	{'c', ft_print_char},
	{'s', ft_print_string},
	{'p', ft_print_pointer},
	{'d', ft_print_int},
	{'i', ft_print_int},
	{'u', ft_print_uint},
	{'x', ft_print_hex_low},
	{'X', ft_print_hex_up},
	{'\0', NULL}
};

t_printer				ft_get_printer(int chr);

#endif
