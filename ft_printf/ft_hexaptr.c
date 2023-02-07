/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:38:00 by lboulatr          #+#    #+#             */
/*   Updated: 2022/11/24 15:32:43 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_base_hexa_ptr(unsigned long long nbr, char *base, int *x)
{
	if (nbr >= 0 && nbr < 16)
	{
		ft_putchar_fd(base[nbr], 1);
		(*x)++;
	}
	else if (nbr < 0)
	{
		ft_putchar_fd('-', 1);
		ft_putnbr_base_hexa_ptr((nbr * (-1)), base, x);
	}
	else if (nbr >= 16)
	{
		ft_putnbr_base_hexa_ptr((nbr / 16), base, x);
		ft_putnbr_base_hexa_ptr((nbr % 16), base, x);
	}
	return ((*x));
}

int	ft_hexaptr(unsigned long long nbr, int c, char *b, int *x)
{
	if (c == 1)
	{
		ft_putstr_fd("0x", 1);
		return (ft_putnbr_base_hexa_ptr(nbr, b, x) + 2);
	}
	return (ft_putnbr_base_hexa_ptr(nbr, b, x));
}
