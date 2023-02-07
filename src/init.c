/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:32:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/05 16:49:43 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_coord_perso(t_game *g)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (g->array[i])
	{
		while (g->array[i][j])
		{
			if (g->array[i][j] == 'P')
			{
				g->x = i;
				g->y = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}	
}

static void	check_images(t_game *game)
{
	if (game->space == NULL \
		|| game->wall == NULL \
		|| game->collect == NULL \
		|| game->exit == NULL \
		|| game->exit_open == NULL \
		|| game->perso == NULL \
		|| game->perso_2 == NULL
		|| game->left == NULL \
		|| game->right == NULL)
		display_error(game, 5);
}

static void	init_images(t_game *game)
{
	game->space = mlx_xpm_file_to_image(game->mlx, "./images/space.xpm", \
										&game->pix, &game->pix);
	game->wall = mlx_xpm_file_to_image(game->mlx, "./images/wall.xpm", \
										&game->pix, &game->pix);
	game->collect = mlx_xpm_file_to_image(game->mlx, "./images/burger1.xpm", \
										&game->pix, &game->pix);
	game->exit = mlx_xpm_file_to_image(game->mlx, "./images/door-closed.xpm", \
										&game->pix, &game->pix);
	game->exit_open = mlx_xpm_file_to_image(game->mlx, "./images/dopen.xpm", \
										&game->pix, &game->pix);
	game->perso = mlx_xpm_file_to_image(game->mlx, "./images/perso.xpm", \
										&game->pix, &game->pix);
	game->perso_2 = mlx_xpm_file_to_image(game->mlx, "./images/perso_2.xpm", \
										&game->pix, &game->pix);
	game->left = mlx_xpm_file_to_image(game->mlx, "./images/left.xpm", \
										&game->pix, &game->pix);
	game->right = mlx_xpm_file_to_image(game->mlx, "./images/right.xpm", \
										&game->pix, &game->pix);
	check_images(game);
}

static void	init_struct_bis(t_game *game, char *argvone)
{
	game->lines = ft_count_lines(argvone);
	game->rows = ft_count_rows(argvone, game->lines - 1, 0, 0);
	if (game->rows == -1)
		display_error(game, 1);
	game->pix = 75;
	game->x = 1;
	game->y = 1;
	game->win = 0;
	game->ct_col = 0;
	game->x_exit = 0;
	game->y_exit = 0;
	game->move = 0;
	game->str = one_str(argvone, game, 0, 0);
	if (!game->str)
		display_error(game, 5);
	game->array = ft_array(game->str, game);
	if (!game->array)
		display_error(game, 5);
}

void	init_struct(t_game *game, char *argvone)
{
	int		x;

	init_struct_bis(game, argvone);
	x = check_map(game->array, argvone, game->lines);
	if (x != 0)
		display_error(game, x);
	ft_exit_coord(game, 0, 0);
	ft_coord_perso(game);
	if (path_manager_e(game) == -1)
		display_error(game, 3);
	if (path_manager_c(game) == -1)
		display_error(game, 4);
	game->allcol = collectible(game, 0, 0);
	game->mlx = mlx_init();
	if (!game->mlx)
		display_error(game, 5);
	game->window = mlx_new_window(game->mlx, (game->rows * game->pix), \
				(game->lines * game->pix), "Tasmanian : Liberty City Stories");
	if (!game->window)
		display_error(game, 5);
	init_images(game);
	window_display(game, 0, 0);
}
