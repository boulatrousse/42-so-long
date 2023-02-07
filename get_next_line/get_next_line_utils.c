/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:28:33 by lboulatr          #+#    #+#             */
/*   Updated: 2023/01/23 14:43:22 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free(char *str)
{
	free(str);
	return (0);
}

int	ft_strchr_n(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
	{	
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

int	ft_strlen_bis(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str && str[i] && str[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_bis(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = ft_strlen_gnl(s1) + ft_strlen_bis(s2);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = -1;
	j = 0;
	while (s1 && s1[++i])
		dest[i] = s1[i];
	if (i == -1)
		i = 0;
	while (s2 && s2[j] && s2[j] != '\n')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = s2[j];
	if (s2[j] == '\n')
		j++;
	dest[i + j] = '\0';
	free((void *)s1);
	return (dest);
}
