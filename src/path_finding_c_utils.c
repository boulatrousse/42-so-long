/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_c_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:35:56 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 10:55:46 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	col_count(char **array)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (array[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	init_struct_collec(t_game *g, t_col *col, char **array)
{
	col->x = 0;
	col->y = 0;
	col->x_perso = g->x;
	col->y_perso = g->y;
	col->count = col_count(array);
}

int	ft_check_col(char **array, t_col *col)
{
	int		a;

	a = 0;
	if (array[col->x + 1][col->y] == '1' || array[col->x + 1][col->y] == 'E')
		a++;
	if (array[col->x - 1][col->y] == '1' || array[col->x - 1][col->y] == 'E')
		a++;
	if (array[col->x][col->y + 1] == '1' || array[col->x][col->y + 1] == 'E')
		a++;
	if (array[col->x][col->y - 1] == '1' || array[col->x][col->y - 1] == 'E')
		a++;
	if (a == 4)
		return (-1);
	return (0);
}

int	ft_pec(t_game *g, char **array)
{
	int		a;

	a = 0;
	if (array[g->x + 1][g->y] == '1' || array[g->x + 1][g->y] == 'E')
		a++;
	if (array[g->x - 1][g->y] == '1' || array[g->x - 1][g->y] == 'E')
		a++;
	if (array[g->x][g->y + 1] == '1' || array[g->x][g->y + 1] == 'E')
		a++;
	if (array[g->x][g->y - 1] == '1' || array[g->x][g->y - 1] == 'E')
		a++;
	if (a == 4)
		return (-1);
	return (0);
}
