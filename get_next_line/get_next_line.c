/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:28:36 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/22 11:27:17 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_cut_buffer(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (j < BUFFER_SIZE - i)
	{
		str[j] = str[j + i];
		j++;
	}
	str[j] = '\0';
}

static char	*check_line(char *line, char *buffer)
{
	char	*res;

	ft_cut_buffer(buffer);
	res = ft_strjoin_bis(line, buffer);
	if (!res)
		exit(EXIT_FAILURE);
	if (res[0] == '\0')
		res = ft_free(res);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			x;

	x = 1;
	line = NULL;
	if (read(fd, NULL, 0) == -1 || fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (buffer[0] = 0, NULL);
	if (ft_strchr_n(buffer) != -1)
		line = check_line(line, buffer);
	while (ft_strchr_n(buffer) == -1 && x > 0)
	{
		x = read(fd, buffer, BUFFER_SIZE);
		if (x <= 0)
			return (line);
		buffer[x] = '\0';
		line = ft_strjoin_bis(line, buffer);
		if (!line)
			exit(EXIT_FAILURE);
	}
	return (line);
}
