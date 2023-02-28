/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:05:46 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/28 10:13:43 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_strings(t_game *game)
{
	free(game->str);
	free_array(game->array);
}

void	free_mlx(t_game *game)
{
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

void	free_window(t_game *game)
{
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
}

void	map_format_error(char *str, char **array)
{
	free(str);
	free_array(array);
	display_error("Error\nWrong map format.\n");
}
