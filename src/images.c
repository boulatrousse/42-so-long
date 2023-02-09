/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:03:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 10:51:52 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_images(t_game *game)
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

void	init_images(t_game *game)
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

void	ft_clear_images(t_game *game)
{
	if (game->space)
		mlx_destroy_image(game->mlx, game->space);
	if (game->wall)
		mlx_destroy_image(game->mlx, game->wall);
	if (game->collect)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit)
		mlx_destroy_image(game->mlx, game->exit);
	if (game->exit_open)
		mlx_destroy_image(game->mlx, game->exit_open);
	if (game->perso)
		mlx_destroy_image(game->mlx, game->perso);
	if (game->perso_2)
		mlx_destroy_image(game->mlx, game->perso_2);
	if (game->left)
		mlx_destroy_image(game->mlx, game->left);
	if (game->right)
		mlx_destroy_image(game->mlx, game->right);
}

void	window_display(t_game *g, int i, int j)
{
	while (g->array[i])
	{
		while (g->array[i][j])
		{
			if (g->array[i][j] == '0')
				mlx_put_image_to_window(g->mlx, g->window, \
										g->space, (j * g->pix), (i * g->pix));
			else if (g->array[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->window, \
										g->wall, (j * g->pix), (i * g->pix));
			else if (g->array[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->window, \
										g->collect, (j * g->pix), (i * g->pix));
			else if (g->array[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->window, \
										g->exit, (j * g->pix), (i * g->pix));
			else if (g->array[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->window, \
										g->perso, (j * g->pix), (i * g->pix));
			j++;
		}
		j = 0;
		i++;
	}
}
