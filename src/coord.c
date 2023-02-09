/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 10:53:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 11:00:31 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit_coord(t_game *g, int i, int j)
{
	while (g->array[i])
	{
		while (g->array[i][j])
		{
			if (g->array[i][j] == 'E')
			{
				g->x_exit = i;
				g->y_exit = j;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_coord_perso(t_game *g)
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

void	ft_col_coord(char **array, t_col *col)
{
	while (array[col->x])
	{
		while (array[col->x][col->y])
		{
			if (array[col->x][col->y] == 'C')
				return ;
			col->y++;
		}
		col->y = 0;
		col->x++;
	}
}
