/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_usign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:06:03 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/22 17:01:47 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_fd_usign_bis(unsigned int n, int fd)
{
	if (n == 4294967295)
		write(fd, "4294967295", 10);
	else
	{
		if (n >= 0 && n <= 9)
			ft_putchar_fd_pf(n + 48, fd);
		else if (n < 0)
		{
			ft_putchar_fd_pf('-', fd);
			ft_putnbr_fd_usign(n * (-1), fd);
		}
		else
		{
			ft_putnbr_fd_usign((n / 10), fd);
			ft_putnbr_fd_usign((n % 10), fd);
		}
	}
}

int	ft_putnbr_fd_usign(unsigned int n, int fd)
{
	ft_putnbr_fd_usign_bis(n, fd);
	return ((long long int)count(n));
}
