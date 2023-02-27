/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:32:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/27 17:17:34 by lboulatr         ###   ########.fr       */
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

int	is_charset_col(int c, t_col *col)
{
	if (c == 'C' || c == '0' || c == 'P')
		return (1);
	if (c == 'E' && col->count != 0)
		return (-1);
	return (0);
}

void	ft_exit(t_game *g)
{
	if (g->str)
		free(g->str);
	if (g->array)
		free_array(g->array);
	ft_clear_images_character(g);
	mlx_clear_window(g->mlx, g->window);
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(EXIT_SUCCESS);
}

int	ft_strlen_sl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
