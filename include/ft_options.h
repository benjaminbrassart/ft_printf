/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:46:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/06/30 20:57:15 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONS
# define FT_OPTIONS

# include <stdarg.h>
# include <stdint.h>

enum e_opt
{
	MIN_WIDTH = 1 << 0,
	PRECISION = 1 << 1,
	UPPERCASE = 1 << 2,
	DASH = 1 << 3,
	ZERO = 1 << 4
};

typedef struct s_opt
{
	uint8_t	flags;
	int		precision;
	int		min_width;
}	t_opt;

t_opt	*ft_parse_options(char const **p_format, va_list args);

#endif
