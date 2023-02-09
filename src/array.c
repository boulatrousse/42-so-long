/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:19:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 13:13:26 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!str)
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
