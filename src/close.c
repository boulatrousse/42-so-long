/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:12:04 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/02 10:13:45 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	close_fd(void)
{
	int		i;

	i = 0;
	while (i <= 1023)
	{
		close(i);
		i++;
	}
}

int	ft_close_win(t_game *g)
{
	ft_exit(g);
	return (0);
}

void	ft_exit(t_game *g)
{
	if (g->str)
		free(g->str);
	if (g->array)
		free_array(g->array);
	ft_clear_images_character(g);
	mlx_clear_window(g->mlx, g->window);
	mlx_destroy_window(g->mlx, g->window);
	mlx_destroy_display(g->mlx);
	free(g->mlx);
	close_fd();
	exit(EXIT_SUCCESS);
}
