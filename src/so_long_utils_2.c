/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:32:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 11:04:25 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	char_is_ok(int c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'P')
		return (0);
	else if (c == 'E')
		return (0);
	else if (c == 'C')
		return (0);
	return (-1);
}

int	is_charset(int c)
{
	if (c == 'C' || c == '0' || c == 'P' || c == 'E')
		return (1);
	return (0);
}

int	is_charset2(int c, t_col *col)
{
	if (c == 'C' || c == '0' || c == 'P')
		return (1);
	if (c == 'E' && col->count != 0)
		return (-1);
	return (0);
}
