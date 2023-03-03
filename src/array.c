/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:19:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/03 11:28:47 by lboulatr         ###   ########.fr       */
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

static void	free_one_str(char *str)
{
	free(str);
	display_error("Error\nMalloc error.\n");
}

char	*one_str(char *argvone, int fd, int x)
{
	t_onestr	onestr;

	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		display_error("Error\nFD error.\n");
	onestr.str = get_next_line(fd);
	if (!onestr.str)
		display_error("Error\nMalloc error.\n");
	while (x != 0)
	{
		onestr.tmp = onestr.str;
		if (!onestr.tmp)
			free_one_str(onestr.str);
		onestr.gnl = get_next_line(fd);
		if (!onestr.gnl)
			free_gnl(onestr.tmp, onestr.gnl, onestr.str);
		onestr.str = ft_strjoin(onestr.tmp, onestr.gnl);
		if (!onestr.str)
			free_gnl(onestr.tmp, onestr.gnl, onestr.str);
		free(onestr.tmp);
		free(onestr.gnl);
		x--;
	}
	return (close(fd), onestr.str);
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
