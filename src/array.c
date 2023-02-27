/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:19:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/27 17:23:30 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_gnl(char *tmp, char *gnl, char *str)
{
	if (str)
		free(str);
	else if (gnl && tmp)
	{
		free(gnl);
		free(tmp);
	}
	display_error("Error\nMalloc error.\n");
}

char	*one_str(char *argvone, t_game *g, int fd, int x)
{
	char	*str;
	char	*tmp;
	char	*gnl;

	x = g->lines - 1;
	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		display_error("Error\nFD error.\n");
	str = get_next_line(fd);
	if (!str)
		display_error("Error\nMalloc error.\n");
	while (x != 0)
	{
		tmp = str;
		gnl = get_next_line(fd);
		if (!gnl)
			free_gnl(tmp, gnl, str);
		str = ft_strjoin(tmp, gnl);
		if (!str)
			free_gnl(tmp, gnl, str);
		free(gnl);
		free(tmp);
		x--;
	}
	return (close(fd), str);
}

char	**ft_array(char *str)
{
	char	**array;

	array = ft_split(str, '\n');
	if (!array)
	{
		free(str);
		display_error("Error\nMalloc error.\n");
	}
	return (array);
}

void	free_array(char **array)
{
	int		i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	else
		return ;
}
