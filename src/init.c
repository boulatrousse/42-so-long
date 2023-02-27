/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:32:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/27 17:30:12 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_int(t_game *game, char *argvone)
{
	game->lines = ft_count_lines(argvone);
	if (game->lines == -1)
		display_error("Error\nMap doesn't exist or is empty.\n");
	if (game->lines == 1)
		display_error("Error\nInvalid rows or lines.\n");
	game->rows = ft_count_rows(argvone, game->lines - 1, 0, 0);
	if (game->rows == -1)
		display_error("Error\nInvalid rows or lines.\n");
	game->pix = 75;
	game->x = 1;
	game->y = 1;
	game->win = 0;
	game->ct_col = 0;
	game->x_exit = 0;
	game->y_exit = 0;
	game->move = 0;
}

static void	init_map(t_game *game, char *argvone)
{
	game->str = one_str(argvone, game, 0, 0);
	if (!game->str)
		display_error("Error\nMalloc error.\n");
	game->array = ft_array(game->str);
	if (!game->array)
	{
		free(game->str);
		display_error("Error\nMalloc error.\n");
	}
}

static void	init_path_finding(t_game *game, char *argvone)
{
	check_map(game->array, argvone, game->lines, game->str);
	ft_exit_coord(game, 0, 0);
	ft_coord_perso(game);
	if (path_manager_e(game) == -1)
	{
		free_strings(game);
		display_error("Error\nYou can't reach the exit.\n");
	}
	if (path_manager_c(game) == -1)
	{
		free_strings(game);
		display_error("Error\nYou can't reach a collectible.\n");
	}
	game->allcol = count_collectible(game);
}

static void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_strings(game);
		display_error("Error\nMalloc error.\n");
	}
	game->window = mlx_new_window(game->mlx, (game->rows * game->pix), \
				(game->lines * game->pix), "Tasmanian : Liberty City Stories");
	if (!game->window)
	{
		free_strings(game);
		free_mlx(game);
		display_error("Error\nMalloc error.\n");
	}
	init_images(game);
	window_display(game, 0, 0);
}

void	init_struct(t_game *game, char *argvone)
{
	init_int(game, argvone);
	init_map(game, argvone);
	init_path_finding(game, argvone);
	init_window(game);
}
