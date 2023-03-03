/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:18:32 by lboulatr          #+#    #+#             */
/*   Updated: 2023/03/03 13:43:12 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc == 1)
	{
		ft_putstr_fd("Error\nToo few arguments.\n", STDERR_FILENO);
		close_fd();
	}
	if (argc == 2)
	{
		init_struct(&game, argv[1]);
		mlx_hook(game.window, 2, 1L << 0, ft_moves, &game);
		mlx_hook(game.window, 17, 1L << 17, ft_close_win, &game);
		mlx_loop(game.mlx);
	}
	if (argc > 2)
	{
		ft_putstr_fd("Error\nToo many arguments.\n", STDERR_FILENO);
		close_fd();
	}
	return (0);
}
