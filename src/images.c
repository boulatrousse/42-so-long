/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:03:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/21 11:06:55 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_clear_images2(t_game *game)
{	
	if (game->exit_open)
	{
		mlx_destroy_image(game->mlx, game->exit_open);
		game->exit_open = NULL;
	}
	if (game->perso)
	{
		mlx_destroy_image(game->mlx, game->perso);
		game->perso = NULL;
	}
	if (game->perso_2)
	{
		mlx_destroy_image(game->mlx, game->perso_2);
		game->perso_2 = NULL;
	}
	if (game->left)
	{
		mlx_destroy_image(game->mlx, game->left);
		game->left = NULL;
	}
	if (game->right)
	{
		mlx_destroy_image(game->mlx, game->right);
		game->right = NULL;
	}
}

void	ft_clear_images(t_game *game)
{
	if (game->space)
	{
		mlx_destroy_image(game->mlx, game->space);
		game->space = NULL;
	}
	if (game->wall)
	{
		mlx_destroy_image(game->mlx, game->wall);
		game->wall = NULL;
	}
	if (game->collect)
	{
		mlx_destroy_image(game->mlx, game->collect);
		game->collect = NULL;
	}
	if (game->exit)
	{
		mlx_destroy_image(game->mlx, game->exit);
		game->exit = NULL;
	}
	ft_clear_images2(game);
}

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
