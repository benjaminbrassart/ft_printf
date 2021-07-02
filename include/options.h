/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:46:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/02 03:06:17 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <stdarg.h>
# include <stdint.h>

# define MIN_WIDTH __MIN_WIDTH // 1
# define PRECISION __PRECISION // 2
# define UPPERCASE __UPPERCASE // 4
# define DASH __DASH // 8
# define ZERO __ZERO // 16

enum e_opt
{
	__MIN_WIDTH = 1 << 0,
	__PRECISION = 1 << 1,
	__UPPERCASE = 1 << 2,
	__DASH = 1 << 3,
	__ZERO = 1 << 4
};

typedef struct s_opt
{
	uint16_t	flags;
	int			precision;
	int			min_width;
}	t_opt;

t_opt	*ft_parse_options(char const **p_format, va_list args);

#endif
