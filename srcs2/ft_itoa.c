/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 12:22:42 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/15 12:58:52 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		div;
	char	*num;

	if (!(num = (char *)malloc(sizeof(char) * 12)))
		return (NULL);
	if ((i = 0) == 0 && n == 0)
		return ("0");
	if ((div = 1000000000) > 0 && n < 0)
	{
		num[i++] = '-';
		if (n == -2147483648)
			num[i++] = '2';
		n = n == -2147483648 ? 147483648 : -n;
	}
	while (n / div == 0)
		div = div / 10;
	while (div > 0)
	{
		num[i++] = n / div + '0';
		n = n % div;
		div = div / 10;
	}
	num[i] = '\0';
	return (num);
}
