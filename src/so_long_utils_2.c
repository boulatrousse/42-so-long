/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 13:32:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/07 14:17:09 by lboulatr         ###   ########.fr       */
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

void	ft_exit(t_game *g)
{
	if (g->str)
		free(g->str);
	if (g->array)
		free_array(g->array);
	ft_clear_images(g);
	mlx_clear_window(g->mlx, g->window);
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(EXIT_SUCCESS);
}

void	display_error(t_game *g, int x)
{
	if (x == 1)
		ft_putstr_fd("Error\nInvalid rows or lines.\n", STDERR_FILENO);
	else if (x < 0)
		ft_errors(x);
	else if (x == 3)
		ft_putstr_fd("Error\nYou can't reach the exit.\n", STDERR_FILENO);
	else if (x == 4)
		ft_putstr_fd("Error\nYou can't reach a collectible.\n", STDERR_FILENO);
	else if (x == 5)
		ft_putstr_fd("Error\nMalloc error.\n", STDERR_FILENO);
	if (x != 1)
	{
		free(g->str);
		free_array(g->array);
	}
	if (x == 5)
	{
		ft_clear_images(g);
		mlx_clear_window(g->mlx, g->window);
		mlx_destroy_window(g->mlx, g->window);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
	}
	exit(EXIT_FAILURE);
}

int	ft_close_win(t_game *g)
{
	ft_exit(g);
	return (0);
}
