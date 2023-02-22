/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:05:46 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/22 15:38:04 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else if (x == 5 || x == 6)
		ft_putstr_fd("Error\nMalloc error.\n", STDERR_FILENO);
	if (x != 1 && x != 5 && x != 6)
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

void	ft_errors(int x)
{
	if (x == -1)
		ft_putstr_fd("Error\nCheck the letters E, C or P.\n", STDERR_FILENO);
	if (x == -2)
		ft_putstr_fd("Error\nThere's an error in the walls.\n", STDERR_FILENO);
	if (x == -3)
		ft_putstr_fd("Error\nUnknown letter in the map.\n", STDERR_FILENO);
	if (x == -4)
		ft_putstr_fd("Error\nWrong map format.\n", STDERR_FILENO);
	if (x == -5)
		ft_putstr_fd("Error\nMap doesn't exist.\n", STDERR_FILENO);
}
