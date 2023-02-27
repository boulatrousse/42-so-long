/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 10:14:07 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/27 17:31:10 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_pos(t_game *g, t_col *col, char **array)
{
	if (is_charset_col(array[col->x_perso][col->y_perso + 1], col) == 1)
	{
		array[col->x_perso][col->y_perso] = '2';
		col->y_perso++;
		if (path_finder_c(g, col, array) == -1)
			col->y_perso--;
		else
			return (1);
	}
	if (is_charset_col(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	{
		array[col->x_perso][col->y_perso] = '2';
		col->x_perso++;
		if (path_finder_c(g, col, array) == -1)
			col->x_perso--;
		else
			return (1);
	}
	if (is_charset_col(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	return (0);
}

static int	ft_min(t_game *g, t_col *col, char **array)
{
	if (is_charset_col(array[col->x_perso][col->y_perso - 1], col) == 1)
	{
		array[col->x_perso][col->y_perso] = '2';
		col->y_perso--;
		if (path_finder_c(g, col, array) == -1)
			col->y_perso++;
		else
			return (1);
	}
	if (is_charset_col(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	if (is_charset_col(array[col->x_perso - 1][col->y_perso], col) == 1)
	{
		array[col->x_perso][col->y_perso] = '2';
		col->x_perso--;
		if (path_finder_c(g, col, array) == -1)
			col->x_perso++;
		else
			return (1);
	}
	if (is_charset_col(array[col->x_perso][col->y_perso], col) == -1)
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
	if (is_charset_col(array[col->x_perso][col->y_perso], col) == 1)
	{
		if (ft_pos(g, col, array) == 1)
			return (1);
		if (ft_min(g, col, array) == 1)
			return (1);
	}
	if (is_charset_col(array[col->x_perso][col->y_perso], col) == -1)
		return (-1);
	return (ft_check(col, array));
}

int	path_manager_c(t_game *g)
{
	t_col	col;

	col.tmp_str = ft_strdup(g->str);
	if (!col.tmp_str)
		return (-1);
	col.array = ft_split(col.tmp_str, '\n');
	if (!col.array)
		return (free(col.tmp_str), -1);
	init_struct_collec(g, &col);
	while (col.count > 0)
	{
		ft_col_coord(col.array, &col);
		if (ft_check_col(col.array, &col) == -1 || \
			path_finder_c(g, &col, col.array) == -1 || \
			check_trap(g, col.array) == -1)
			return (free_pathfinding_c(col.tmp_str, col.array), -1);
		free_array(col.array);
		col.array = ft_split(col.tmp_str, '\n');
		col.y++;
		col.count--;
	}
	free_pathfinding_c(col.tmp_str, col.array);
	return (0);
}
