/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 14:03:19 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/05 14:05:11 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
