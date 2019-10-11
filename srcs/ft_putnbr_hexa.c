/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:14:16 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/11 12:20:39 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void ft_putnbr_hexa(int nbr)
{
	long int	nbr2;
	int			i;
	char		*base;

	base = "0123456789abcdef";
	nbr2 = (long)nbr;
	if (nbr2 < 0)
	{
		nbr2 = nbr2 * -1;
		ft_putchar('-');
	}
	if (nbr2 < i)
		ft_putchar(base[nbr2]);
	if (nbr2 >= i)
	{
		ft_putnbr_hexa(nbr2 / i);
		ft_putchar(base[nbr2 % i]);
	}
}

int main()
{
	ft_putnbr_hexa(15);
	return (0);
}
