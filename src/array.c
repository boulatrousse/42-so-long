/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:19:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/07 14:16:23 by lboulatr         ###   ########.fr       */
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

int	collectible(t_game *g, int i, int j)
{
	int		x;

	x = 0;
	while (g->array[i])
	{
		while (g->array[i][j])
		{
			if (g->array[i][j] == 'C')
				x++;
			j++;
		}
		j = 0;
		i++;
	}
	return (x);
}

char	*one_str(char *argvone, t_game *g, int fd, int x)
{
	char	*str;
	char	*tmp;
	char	*gnl;

	x = g->lines - 1;
	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		display_error(g, 5);
	str = get_next_line(fd);
	if (!str || (read(fd, NULL, 0) == -1))
		display_error(g, 5);
	while (x != 0)
	{
		tmp = str;
		gnl = get_next_line(fd);
		if (!gnl)
			display_error(g, 5);
		str = ft_strjoin(tmp, gnl);
		if (!str)
			display_error(g, 5);
		free(tmp);
		free(gnl);
		x--;
	}
	return (close(fd), str);
}

char	**ft_array(char *str, t_game *g)
{
	char	**array;

	array = ft_split(str, '\n');
	if (!array)
		display_error(g, 5);
	return (array);
}
