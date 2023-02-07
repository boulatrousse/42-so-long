/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 09:24:22 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/24 15:32:37 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_hexa(unsigned int nbr, char *base, int *x)
{
	if (nbr >= 0 && nbr < 16)
	{
		ft_putchar_fd(base[nbr], 1);
		(*x)++;
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base_hexa((nbr * (-1)), base, x);
	}
	else if (nbr >= 16)
	{
		ft_putnbr_base_hexa((nbr / 16), base, x);
		ft_putnbr_base_hexa((nbr % 16), base, x);
	}
	return ((*x));
}

int	ft_hexa(unsigned int nbr, int check, char *base, int *x)
{
	if (check == 1)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_base_hexa(nbr, base, x) + 2);
	}
	return (ft_putnbr_base_hexa(nbr, base, x));
}
