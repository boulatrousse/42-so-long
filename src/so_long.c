/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:18:32 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/09 11:00:34 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_win(t_game *g)
{
	ft_exit(g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc == 1)
	{
		ft_putstr_fd("Error\nToo few arguments.\n", STDERR_FILENO);
	}
	if (argc == 2)
	{
		init_struct(&game, argv[1]);
		mlx_hook(game.window, 2, 1L << 0, ft_moves, &game);
		mlx_hook(game.window, 17, 1L << 17, ft_close_win, &game);
		mlx_loop(game.mlx);
	}
	return (0);
}
