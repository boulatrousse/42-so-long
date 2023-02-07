/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:30:07 by lboulatr          #+#    #+#             */
/*   Updated: 2023/01/29 13:31:16 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_w(t_game *g)
{
	if (g->array[g->x - 1][g->y] == 'E' && (g->ct_col != g->allcol))
		return ;
	mlx_put_image_to_window(g->mlx, g->window, g->space, \
							(g->y * g->pix), ((g->x * g->pix)));
	mlx_put_image_to_window(g->mlx, g->window, g->perso, \
							(g->y * g->pix), ((g->x * g->pix) - g->pix));
	g->x -= 1;
	if (g->array[g->x][g->y] == 'C')
	{	
		g->array[g->x][g->y] = '0';
		g->ct_col++;
	}
	if (g->array[g->x][g->y] == 'E' && (g->ct_col == g->allcol))
		ft_exit(g);
	g->move++;
	ft_printf("Moves : %d\n", g->move);
}

static void	ft_s(t_game *g)
{
	if (g->array[g->x + 1][g->y] == 'E' && (g->ct_col != g->allcol))
		return ;
	mlx_put_image_to_window(g->mlx, g->window, g->space, \
									(g->y * g->pix), ((g->x * g->pix)));
	mlx_put_image_to_window(g->mlx, g->window, g->perso, \
							(g->y * g->pix), ((g->x * g->pix) + g->pix));
	g->x += 1;
	if (g->array[g->x][g->y] == 'C')
	{	
		g->array[g->x][g->y] = '0';
		g->ct_col++;
	}
	if (g->array[g->x][g->y] == 'E' && (g->ct_col == g->allcol))
		ft_exit(g);
	g->move++;
	ft_printf("Moves : %d\n", g->move);
}

static void	ft_a(t_game *g)
{
	if (g->array[g->x][g->y - 1] == 'E' && (g->ct_col != g->allcol))
		return ;
	mlx_put_image_to_window(g->mlx, g->window, g->space, \
							(g->y * g->pix), ((g->x * g->pix)));
	mlx_put_image_to_window(g->mlx, g->window, g->left, \
							((g->y * g->pix) - g->pix), (g->x * g->pix));
	g->y -= 1;
	if (g->array[g->x][g->y] == 'C')
	{	
		g->array[g->x][g->y] = '0';
		g->ct_col++;
	}
	if (g->array[g->x][g->y] == 'E' && (g->ct_col == g->allcol))
		ft_exit(g);
	g->move++;
	ft_printf("Moves : %d\n", g->move);
}

static void	ft_d(t_game *g)
{
	if (g->array[g->x][g->y + 1] == 'E' && (g->ct_col != g->allcol))
		return ;
	mlx_put_image_to_window(g->mlx, g->window, g->space, \
							(g->y * g->pix), ((g->x * g->pix)));
	mlx_put_image_to_window(g->mlx, g->window, g->right, \
							((g->y * g->pix) + g->pix), (g->x * g->pix));
	g->y += 1;
	if (g->array[g->x][g->y] == 'C')
	{	
		g->array[g->x][g->y] = '0';
		g->ct_col++;
	}
	if (g->array[g->x][g->y] == 'E' && (g->ct_col == g->allcol))
		ft_exit(g);
	g->move++;
	ft_printf("Moves : %d\n", g->move);
}

int	ft_moves(int key_code, t_game *g)
{
	if (key_code == 65307)
		ft_exit(g);
	if (key_code == 119 && (g->array[g->x - 1][g->y] != '1'))
		ft_w(g);
	if (key_code == 115 && (g->array[g->x + 1][g->y] != '1'))
		ft_s(g);
	if (key_code == 97 && (g->array[g->x][g->y - 1] != '1'))
		ft_a(g);
	if (key_code == 100 && (g->array[g->x][g->y + 1] != '1'))
		ft_d(g);
	if (g->ct_col == g->allcol)
		mlx_put_image_to_window(g->mlx, g->window, g->exit_open, \
		(g->y_exit * g->pix), (g->x_exit * g->pix));
	return (0);
}
