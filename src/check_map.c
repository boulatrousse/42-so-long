/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:02:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/27 17:10:10 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall(char **array, int lines, int i, int j)
{
	while (i <= (lines - 2))
	{
		if (array[i][0] != '1')
			return (-1);
		while (array[i][j] != '\0')
			j++;
		if (array[i][j - 1] != '1')
			return (-1);
		j = 0;
		i++;
	}
	return (0);
}

static int	check_wall_first_last(char **array, int lines, int j)
{
	while (array[0][j])
	{
		if (array[0][j] != '1')
			return (-1);
		j++;
	}
	j = 0;
	while (array[lines - 1][j] != '\0')
	{
		if (array[lines - 1][j] != '1')
			return (-1);
		j++;
	}
	return (0);
}

static int	check_char(char **array, int i, int j)
{
	t_char	chr;

	chr.ct_e = 0;
	chr.ct_c = 0;
	chr.ct_p = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (array[i][j] == 'E')
				chr.ct_e++;
			if (array[i][j] == 'C')
				chr.ct_c++;
			if (array[i][j] == 'P')
				chr.ct_p++;
			j++;
		}
		j = 0;
		i++;
	}
	if (chr.ct_e != 1 || chr.ct_c < 1 || chr.ct_p != 1)
		return (-1);
	return (0);
}

static int	check_letters(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		while (array[i][j])
		{
			if (char_is_ok(array[i][j]) == -1)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	check_map(char **array, char *argvone, int lines, char *str)
{
	int		i;

	i = 0;
	if (check_char(array, 0, 0) == -1)
		return (free(str), free_array(array), \
				display_error("Error\nE, C or P error.\n"), -1);
	if (check_wall(array, lines, 1, 0) == -1
		|| check_wall_first_last(array, lines, 0))
		return (free(str), free_array(array), \
				display_error("Error\nWall error.\n"), -1);
	if (check_letters(array) == -1)
		return (free(str), free_array(array), \
				display_error("Error\nUnknow letter in the map.\n"), -1);
	while (argvone[i] != '.')
		i++;
	if (argvone[i + 1] != 'b')
		return (map_format_error(str, array), -1);
	if (argvone[i + 2] != 'e')
		return (map_format_error(str, array), -1);
	if (argvone[i + 3] != 'r')
		return (map_format_error(str, array), -1);
	if (argvone[i + 4] != '\0')
		return (map_format_error(str, array), -1);
	return (0);
}
