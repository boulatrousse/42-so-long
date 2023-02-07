/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:15:15 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/05 16:52:30 by lboulatr         ###   ########.fr       */
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

void	ft_errors(int x)
{
	if (x == -1)
		ft_putstr_fd("Error\nCheck the letters E, C or P.\n", STDERR_FILENO);
	if (x == -2)
		ft_putstr_fd("Error\nThere's an error in the walls.\n", STDERR_FILENO);
	if (x == -3)
		ft_putstr_fd("Error\nUnknown letter in the map.\n", STDERR_FILENO);
	if (x == -4)
		ft_putstr_fd("Error\nWrong map format.\n", STDERR_FILENO);
}
