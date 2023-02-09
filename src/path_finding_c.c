/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:14:07 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 10:47:30 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_pos(t_game *g, t_col *col, char **array)
{
	if (is_charset2(array[col->x_perso][col->y_perso + 1], col) == 1)
	{
		array[col->x_perso][col->y_perso] = '2';
		col->y_perso++;
		if (path_finder_c(g, col, array) == -1)
			col->y_perso--;
		else
			return (1);
	}
	if (is_charset2(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	{
		array[col->x_perso][col->y_perso] = '2';
		col->x_perso++;
		if (path_finder_c(g, col, array) == -1)
			col->x_perso--;
		else
			return (1);
	}
	if (is_charset2(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	return (0);
}

static int	ft_min(t_game *g, t_col *col, char **array)
{
	if (is_charset2(array[col->x_perso][col->y_perso - 1], col) == 1)
	{
		array[col->x_perso][col->y_perso] = '2';
		col->y_perso--;
		if (path_finder_c(g, col, array) == -1)
			col->y_perso++;
		else
			return (1);
	}
	if (is_charset2(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	if (is_charset2(array[col->x_perso - 1][col->y_perso], col) == 1)
	{
		array[col->x_perso][col->y_perso] = '2';
		col->x_perso--;
		if (path_finder_c(g, col, array) == -1)
			col->x_perso++;
		else
			return (1);
	}
	if (is_charset2(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	return (0);
}

static int	ft_check(t_col *col, char **array)
{
	if (col->x_perso == col->x && col->y_perso == col->y)
		return (1);
	if (array[col->x_perso][col->y_perso - 1] == '2')
		return (-1);
	if (array[col->x_perso][col->y_perso + 1] == '2')
		return (-1);
	if (array[col->x_perso - 1][col->y_perso] == '2')
		return (-1);
	if (array[col->x_perso + 1][col->y_perso] == '2')
		return (-1);
	return (0);
}

int	path_finder_c(t_game *g, t_col *col, char **array)
{
	if (col->x_perso == col->x && col->y_perso == col->y)
		return (1);
	if (is_charset2(array[col->x_perso][col->y_perso], col) == 1)
	{
		if (ft_pos(g, col, array) == 1)
			return (1);
		if (ft_min(g, col, array) == 1)
			return (1);
	}
	if (is_charset2(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	return (ft_check(col, array));
}

int	path_manager_c(t_game *g)
{
	char	*strr;
	char	**array;
	t_col	col;

	strr = ft_strdup(g->str);
	array = ft_split(strr, '\n');
	init_struct_collec(g, &col, array);
	while (col.count > 0)
	{
		ft_col_coord(array, &col);
		if (ft_check_col(array, &col) == -1 || \
			path_finder_c(g, &col, array) == -1)
		{
			free(strr);
			free_array(array);
			return (-1);
		}
		free_array(array);
		array = ft_split(strr, '\n');
		col.y++;
		col.count--;
	}
	free(strr);
	free_array(array);
	return (0);
}
