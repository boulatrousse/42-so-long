/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:45:50 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/11 13:38:06 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_pos(t_game *g, char **array, int i, int j)
{
	if (is_charset(array[i][j + 1]) == 1)
	{
		array[i][j] = '2';
		j++;
		if (path_finder_e(g, array, i, j) == -1)
			j--;
		else
			return (1);
	}
	if (is_charset(array[i + 1][j]) == 1)
	{
		array[i][j] = '2';
		i++;
		if (path_finder_e(g, array, i, j) == -1)
			i--;
		else
			return (1);
	}
	return (0);
}

static int	ft_min(t_game *g, char **array, int i, int j)
{
	if (is_charset(array[i][j - 1]) == 1)
	{
		array[i][j] = '2';
		j--;
		if (path_finder_e(g, array, i, j) == -1)
			j++;
		else
			return (1);
	}
	if (is_charset(array[i - 1][j]) == 1)
	{
		array[i][j] = '2';
		i--;
		if (path_finder_e(g, array, i, j) == -1)
			i++;
		else
			return (1);
	}
	return (0);
}

static int	ft_check(t_game *g, char **array, int i, int j)
{
	if (i == g->x_exit && j == g->y_exit)
		return (1);
	if (array[i][j - 1] == '2')
		return (-1);
	if (array[i][j + 1] == '2')
		return (-1);
	if (array[i - 1][j] == '2')
		return (-1);
	if (array[i + 1][j] == '2')
		return (-1);
	return (0);
}

int	path_finder_e(t_game *g, char **array, int i, int j)
{
	if (i == g->x_exit && j == g->y_exit)
		return (1);
	if (is_charset(array[i][j]) == 1)
	{
		if (ft_pos(g, array, i, j) == 1)
			return (1);
		if (ft_min(g, array, i, j) == 1)
			return (1);
	}
	return (ft_check(g, array, i, j));
}

int	path_manager_e(t_game *g)
{
	int		i;
	int		j;
	char	*strr;
	char	**array;

	i = g->x;
	j = g->y;
	strr = ft_strdup(g->str);
	array = ft_split(strr, '\n');
	if (path_finder_e(g, array, i, j) == -1)
	{
		free(strr);
		free_array(array);
		return (-1);
	}
	free(strr);
	free_array(array);
	return (0);
}
