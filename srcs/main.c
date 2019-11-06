/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:18:59 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/06 14:03:49 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int		 main(void)
{
	char	var;
	char	*s_hidden = "hi low";

	var = 'c';
	printf("RETURN: %d\n", ft_printf("%05i", 43));
	printf("RETURN: %d\n", printf("%05i", 43));
	printf("RETURN: %d\n", ft_printf("%05i", 43));
	printf("RETURN: %d\n", printf("%05i", 43));
	printf("RETURN: %d\n", ft_printf("%05i", 43));
	printf("RETURN: %d\n", printf("%05i", 43));
	printf("RETURN: %d\n", ft_printf("%05i", 43));
	printf("RETURN: %d\n", printf("%05i", 43));

	// printf("RETURN: %d\n", ft_printf("%07i", -54));
	// printf("RETURN: %d\n", printf("%07i", -54));
	// printf("RETURN: %d\n", ft_printf("%03i", 0));
	// printf("RETURN: %d\n", printf("%03i", 0));
	// printf("RETURN: %d\n", ft_printf("this %i number", 0));
	// printf("RETURN: %d\n", printf("this %i number", 0));

	// printf("RETURN: %d\n", ft_printf("%9s", s_hidden));
	// printf("RETURN: %d\n", printf("%9s", s_hidden));
	// printf("RETURN: %d\n", ft_printf("%s\n", NULL));
	// printf("RETURN: %d\n", printf("%s\n", NULL));
	// printf("RETURN: %d\n", ft_printf("%32s\n", NULL));
	// printf("RETURN: %d\n", printf("%32s\n", NULL));
	// printf("RETURN: %d\n", ft_printf("hello, %s.\n", NULL));
	// printf("RETURN: %d\n", printf("hello, %s.\n", NULL));
	// printf("RETURN: %d\n", ft_printf("%s\n", NULL));
	// printf("RETURN: %d\n", printf("%s\n", NULL));
	// printf("RETURN: %d\n", ft_printf("%32s\n", NULL));
	// printf("RETURN: %d\n", printf("%32s\n", NULL));
	// printf("RETURN: %d\n", ft_printf("%20c\n", 'f'));
	// printf("RETURN: %d\n", printf("%20c\n", 'f'));
	// printf("RETURN: %d\n", ft_printf("[%c]\n", 'r'));
	// printf("RETURN: %d\n", printf("[%c]\n", 'r'));
	// printf("RETURN: %d\n", ft_printf("PRINT [%p]\n", &var));
	// printf("RETURN: %d\n", printf("PRINT [%p]\n", &var));
	// printf("RETURN: %d\n", ft_printf("PRINT [%.20u]\n", 4111));
	// printf("RETURN: %d\n", printf("PRINT [%.20u]\n", 4111));
	// printf("RETURN: %d\n", ft_printf("PRINT [%#20X]\n", 11154));
	// printf("RETURN: %d\n", printf("PRINT [%#20X]\n", 11154));
	// printf("RETURN: %d\n", ft_printf("PRINT [%++0.i]\n", 1));
	// printf("RETURN: %d\n", printf("PRINT [%+0.i]\n", 1));
	// printf("RETURN: %d\n", ft_printf("[%c]\n", '\0'));
	// printf("RETURN: %d\n", printf("[%c]\n", '\0'));
	// printf("RETURN: %d\n", ft_printf("%.7s\n", "hello"));
	// printf("RETURN: %d\n", printf("%.7s\n", "hello"));
	// printf("RETURN: %d\n", ft_printf("%.2s%.7s\n", "hello", "world"));
	// printf("RETURN: %d\n", printf("%.2s%.7s\n", "hello", "world"));
	// printf("RETURN: %d\n", ft_printf("%.7s%.2s\n", "hello", "world"));
	// printf("RETURN: %d\n", printf("%.7s%.2s\n", "hello", "world"));
	// printf("RETURN: %d\n", ft_printf("s: %s, p: %p, d:%d %%\n", "a string", &var, 42));
	// printf("RETURN: %d\n", printf("s: %s, p: %p, d:%d %%\n", "a string", &var, 42));
	// printf("RETURN: %d\n", ft_printf("{%-15p}", 0));
	// printf("RETURN: %d\n", printf("{%-15p}", 0));
	// printf("RETURN: %d\n", ft_printf("{%-10d}", 42));
	// printf("RETURN: %d\n", printf("{%-10d}", 42));
	//
	// printf("s: %s, p: %p, d:%d", "a string", &var, 42)
	// printf("%u", UINT_MAX)
	// printf("%s %d %p %% %x", "bonjour ", 42, &free, 42)
	// printf("%ld", LONG_MIN)
	// printf("%lld", LLONG_MIN)
	// printf("{%-15p}", 0)
	// printf("{%-10d}", 42)
	// printf("{%010d}", 42)
	// printf("{%+03d}", 0)
	// printf("%15.4d", 42)
	// printf("%.4s", "42")
	// printf("%.c", 0)
	// printf("%.0p, %.p", 0, 0)
	// printf("%u", -42)
	// printf("{%*d}", -5, 42)
	// printf("%*.*d", 0, 3, 0)
	// printf("{%05.*d}", -15, 42)

	// printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
	// printf("{% 20f}{%+0.9lf}{%Lf}", 1.42, 1.42, 1.42l);
	// printf("{% 20e}{%+0.9le}{%Le}", 102354263626420.42, 154.42, 13144311.42l);

	// ft_printf("[%c]\n", 'c');
	// printf("[%c]\n", 'c');
	// ft_printf("%-20c]\n", '\0');
	// printf("%-20c]\n", '\0');
	//
	// printf("%-20s|\n", "Vad");
	// ft_printf("heeeeej\n");
	// ft_printf("heeeeej %40 .3 s\n", "TEseeeeert");
	// ft_printf("[%20.0md]\n", 0);
	// printf("[%20.0md]\n", 0);
	// ft_printf("%.d\n", 1);
	// printf("[%.d]\n", 1);

	// moulitest + filechecker

	return (0);
}
