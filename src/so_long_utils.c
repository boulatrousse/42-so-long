/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:15:15 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/23 16:43:01 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_collectible(t_game *g)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (g->array[i])
	{
		while (g->array[i][j])
		{
			if (g->array[i][j] == 'C')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int	ft_count_lines(char *argvone)
{
	int		count;
	int		fd;
	char	*str;

	count = 0;
	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		return (-1);
	str = get_next_line(fd);
	if (!str)
		exit(EXIT_FAILURE);
	free(str);
	while (str != NULL)
	{
		count++;
		str = get_next_line(fd);
		if (!str)
			break ;
		free(str);
	}
	close(fd);
	return (count);
}

static int	check_gnl(char *str, int fd, int i)
{
	str = get_next_line(fd);
	if (!str)
		exit(EXIT_FAILURE);
	if (ft_strlen_sl(str) != i)
		return (free(str), -1);
	free(str);
	return (0);
}

int	ft_count_rows(char *argvone, int lines, int fd, int i)
{
	char	*str;

	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	if (!str)
		exit(EXIT_FAILURE);
	i = ft_strlen_sl(str);
	free(str);
	while (lines != 1)
	{
		if (check_gnl(str, fd, i) == -1)
			return (-1);
		lines--;
	}
	i--;
	str = get_next_line(fd);
	if (!str)
		exit(EXIT_FAILURE);
	if ((ft_strlen_sl(str)) != i)
		return (free(str), -1);
	free(str);
	close(fd);
	return (i);
}
