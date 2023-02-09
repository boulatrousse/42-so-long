/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:15:15 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 11:12:54 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_sl(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_count_lines(char *argvone)
{
	int		count;
	int		fd;
	char	*str;

	count = 0;
	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	if (str == NULL)
		exit(EXIT_FAILURE);
	free(str);
	while (str != NULL)
	{
		str = get_next_line(fd);
		free(str);
		count++;
	}
	close(fd);
	return (count);
}

int	ft_count_rows(char *argvone, int lines, int fd, int i)
{
	char	*str;

	fd = open(argvone, O_RDONLY);
	if (fd < 0 || fd > 1023)
		exit(EXIT_FAILURE);
	str = get_next_line(fd);
	if (str == NULL)
		exit(EXIT_FAILURE);
	i = ft_strlen_sl(str);
	free(str);
	while (lines != 1)
	{
		str = get_next_line(fd);
		if (ft_strlen_sl(str) != i)
			return (free(str), -1);
		free(str);
		lines--;
	}
	i--;
	str = get_next_line(fd);
	if ((ft_strlen_sl(str)) != i)
		return (free(str), -1);
	free(str);
	close(fd);
	return (i);
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

void	ft_exit(t_game *g)
{
	if (g->str)
		free(g->str);
	if (g->array)
		free_array(g->array);
	ft_clear_images(g);
	mlx_clear_window(g->mlx, g->window);
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	exit(EXIT_SUCCESS);
}
