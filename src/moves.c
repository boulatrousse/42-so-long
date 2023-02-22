/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:30:07 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/22 11:39:21 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_up(t_game *g)
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

static void	move_down(t_game *g)
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

static void	move_left(t_game *g)
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

static void	move_right(t_game *g)
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
	if (key_code == KEY_ESC)
		ft_exit(g);
	if (key_code == KEY_UP && (g->array[g->x - 1][g->y] != '1'))
		move_up(g);
	if (key_code == KEY_DOWN && (g->array[g->x + 1][g->y] != '1'))
		move_down(g);
	if (key_code == KEY_LEFT && (g->array[g->x][g->y - 1] != '1'))
		move_left(g);
	if (key_code == KEY_RIGHT && (g->array[g->x][g->y + 1] != '1'))
		move_right(g);
	if (g->ct_col == g->allcol)
		mlx_put_image_to_window(g->mlx, g->window, g->exit_open, \
		(g->y_exit * g->pix), (g->x_exit * g->pix));
	return (0);
}
