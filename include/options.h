/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 20:46:12 by bbrassar          #+#    #+#             */
/*   Updated: 2021/09/29 03:31:37 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIONS_H
# define OPTIONS_H

# include <stdarg.h>
# include <stdint.h>

# define MIN_WIDTH __MIN_WIDTH
# define PRECISION __PRECISION
# define DASH __DASH
# define ZERO __ZERO
# define SPACE __SPACE
# define PLUS __PLUS
# define HASHTAG __HASHTAG
# define BASE_HEX ("0123456789abcdef")

enum e_opt
{
	__MIN_WIDTH = 1 << 0,
	__PRECISION = 1 << 1,
	__DASH = 1 << 2,
	__ZERO = 1 << 3,
	__SPACE = 1 << 4,
	__PLUS = 1 << 5,
	__HASHTAG = 1 << 6
};

typedef struct s_opt
{
	uint8_t	flags;
	int		precision;
	int		min_width;
}	t_opt;

t_opt	*ft_parse_options(char const **p_format, va_list args);

#endif
