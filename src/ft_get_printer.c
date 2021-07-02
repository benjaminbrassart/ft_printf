/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_printer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrassar <bbrassar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 23:55:08 by bbrassar          #+#    #+#             */
/*   Updated: 2021/07/01 23:56:50 by bbrassar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_functions.h"

t_printer	ft_get_printer(int chr)
{
	int	i;

	i = 0;
	while (g_printers[i].chr != chr && g_printers[i].chr)
		++i;
	return (g_printers[i]);
}
