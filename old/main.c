/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:18:59 by frlindh           #+#    #+#             */
/*   Updated: 2019/11/07 15:26:36 by fredrikalindh    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>
#include <limits.h>

int		 main(void)
{
	char	var;
	char	*s_hidden = "hi low";

	var = 'c';
	printf("RETURN: %d\n", ft_printf("%hi \n", SHRT_MIN));
	printf("RETURN: %d\n", printf("%hi \n", SHRT_MIN));
	printf("RETURN: %d\n", ft_printf("%hi \n", SHRT_MAX));
	printf("RETURN: %d\n", printf("%hi \n", SHRT_MAX));
	printf("RETURN: %d\n", ft_printf("%hu \n", USHRT_MAX));
	printf("RETURN: %d\n", printf("%hu \n", USHRT_MAX));

	printf("RETURN: %d\n", ft_printf("%i \n", INT_MIN));
	printf("RETURN: %d\n", printf("%i \n", INT_MIN));
	printf("RETURN: %d\n", ft_printf("%i \n", INT_MAX));
	printf("RETURN: %d\n", printf("%i \n", INT_MAX));
	printf("RETURN: %d\n", ft_printf("%'li \n", LONG_MIN));
	printf("RETURN: %d\n", printf("%'li \n", LONG_MIN));
	printf("RETURN: %d\n", ft_printf("%'li \n", LONG_MAX));
	printf("RETURN: %d\n", printf("%'li \n", LONG_MAX));
	printf("RETURN: %d\n", ft_printf("%'lli \n", LLONG_MIN));
	printf("RETURN: %d\n", printf("%'lli \n", LLONG_MIN));
	printf("RETURN: %d\n", ft_printf("%'lli \n", LLONG_MAX));
	printf("RETURN: %d\n", printf("%'lli \n", LLONG_MAX));

	printf("RETURN: %d\n", ft_printf("%d \n", INT_MIN));
	printf("RETURN: %d\n", printf("%d \n", INT_MIN));
	printf("RETURN: %d\n", ft_printf("%d \n", INT_MAX));
	printf("RETURN: %d\n", printf("%d \n", INT_MAX));
	printf("RETURN: %d\n", ft_printf("%'ld \n", LONG_MIN));
	printf("RETURN: %d\n", printf("%'ld \n", LONG_MIN));
	printf("RETURN: %d\n", ft_printf("%'ld \n", LONG_MAX));
	printf("RETURN: %d\n", printf("%'ld \n", LONG_MAX));
	printf("RETURN: %d\n", ft_printf("%'lld \n", LLONG_MIN));
	printf("RETURN: %d\n", printf("%'lld \n", LLONG_MIN));
	printf("RETURN: %d\n", ft_printf("%'lld \n", LLONG_MAX));
	printf("RETURN: %d\n", printf("%'lld \n", LLONG_MAX));

	printf("RETURN: %d\n", ft_printf("%u \n", UINT_MAX));
	printf("RETURN: %d\n", printf("%u \n", UINT_MAX));
	printf("RETURN: %d\n", ft_printf("%'lu \n", ULONG_MAX));
	printf("RETURN: %d\n", printf("%'lu \n", ULONG_MAX));
	printf("RETURN: %d\n", ft_printf("%'llu \n", ULLONG_MAX));
	printf("RETURN: %d\n", printf("%'llu \n", ULLONG_MAX));

	printf("RETURN: %d\n", ft_printf("%x \n", UINT_MAX));
	printf("RETURN: %d\n", printf("%x \n", UINT_MAX));
	printf("RETURN: %d\n", ft_printf("%'lx \n", ULONG_MAX));
	printf("RETURN: %d\n", printf("%'lx \n", ULONG_MAX));
	printf("RETURN: %d\n", ft_printf("%'llx \n", ULLONG_MAX));
	printf("RETURN: %d\n", printf("%'llx \n", ULLONG_MAX));
	printf("RETURN: %d\n", ft_printf("%X \n", UINT_MAX));
	printf("RETURN: %d\n", printf("%X \n", UINT_MAX));
	printf("RETURN: %d\n", ft_printf("%'lX \n", ULONG_MAX));
	printf("RETURN: %d\n", printf("%'lX \n", ULONG_MAX));
	printf("RETURN: %d\n", ft_printf("%'llX \n", ULLONG_MAX));
	printf("RETURN: %d\n", printf("%'llX \n", ULLONG_MAX));

	printf("RETURN: %d\n", ft_printf("%X \n", INT_MIN));
	printf("RETURN: %d\n", printf("%X \n", INT_MIN));
	printf("RETURN: %d\n", ft_printf("%X \n", INT_MAX));
	printf("RETURN: %d\n", printf("%X \n", INT_MAX));
	printf("RETURN: %d\n", ft_printf("%'lx \n", LONG_MIN));
	printf("RETURN: %d\n", printf("%'lx \n", LONG_MIN));
	printf("RETURN: %d\n", ft_printf("%'lx \n", LONG_MAX));
	printf("RETURN: %d\n", printf("%'lx \n", LONG_MAX));
	printf("RETURN: %d\n", ft_printf("%'llx \n", LLONG_MIN));
	printf("RETURN: %d\n", printf("%'llx \n", LLONG_MIN));
	printf("RETURN: %d\n", ft_printf("%'llx \n", LLONG_MAX));
	printf("RETURN: %d\n", printf("%'llx \n", LLONG_MAX));




	// printf("RETURN: %d\n", ft_printf("%#.x %#.0x\n", 0, 0));
	// printf("RETURN: %d\n", printf("%#.x %#.0x\n", 0, 0));
	// printf("RETURN: %d\n", ft_printf("this %#-3x number\n", 0));
	// printf("RETURN: %d\n", printf("this %#-3x number\n", 0));
	// printf("RETURN: %d\n", ft_printf("this %#x number\n", 4294967295u));
	// printf("RETURN: %d\n", printf("this %#x number\n", 4294967295u));
	// printf("RETURN: %d\n", ft_printf("%x\n", 4294967295u));
	// printf("RETURN: %d\n", printf("%x\n", 4294967295u));
	// printf("RETURN: %d\n", ft_printf("%08.5i\n", 34));
	// printf("RETURN: %d\n", printf("%08.5i\n", 34));
	// printf("RETURN: %d\n", ft_printf("%010.5i\n", -216));
	// printf("RETURN: %d\n", printf("%010.5i\n", -216));
	// printf("RETURN: %d\n", ft_printf("%05i\n", 43));
	// printf("RETURN: %d\n", printf("%05i\n", 43));
	//
	// printf("RETURN: %d\n", ft_printf("%05i\n", 43));
	// printf("RETURN: %d\n", printf("%05i\n", 43));
	// printf("RETURN: %d\n", ft_printf("%08.5i\n", 34));
	// printf("RETURN: %d\n", printf("%08.5i\n", 34));
	// printf("RETURN: %d\n", ft_printf("%010.5i\n", -216));
	// printf("RETURN: %d\n", printf("%010.5i\n", -216));
	// printf("RETURN: %d\n", ft_printf("%05i\n", 43));
	// printf("RETURN: %d\n", printf("%05i\n", 43));
	//
	// printf("RETURN: %d\n", ft_printf("%07hi", -54));
	// printf("RETURN: %d\n", printf("%07hi", -54));
	// printf("RETURN: %d\n", ft_printf("%03hhi", 30));
	// printf("RETURN: %d\n", printf("%03hhi", 30));
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
	// printf("RETURN: %d\n", ft_printf("PRINT [%p] %%\n", &var));
	// printf("RETURN: %d\n", printf("PRINT [%p] %%\n", &var));
	// printf("RETURN: %d\n", ft_printf("PRINT [%.20u]\n", 4111));
	// printf("RETURN: %d\n", printf("PRINT [%.20u]\n", 4111));
	// printf("RETURN: %d\n", ft_printf("PRINT [%#20X]\n", 11154));
	// printf("RETURN: %d\n", printf("PRINT [%#20X]\n", 11154));
	// printf("RETURN: %d\n", ft_printf("PRINT [%++0.i]\n", 1));
	// printf("RETURN: %d\n", printf("PRINT [%+0.i]\n", 1));
	// printf("RETURN: %d\n", ft_printf("[%c]\n", '\0'));
	// printf("RETURN: %d\n", printf("[%c]\n", '\0'));


	// int test;
	// int fd = open("ft_printf.c");
	// char buf[1000];
	// read(fd, buf, 999);
	// buf[999] = '\0';
	// printf("RETURN: %d %d\n", ft_printf("%.7s %n\n", "hello", &test), test);
	// printf("RETURN: %d %d\n", printf("%.7s %n\n", "hello", &test), test);
	// printf("RETURN: %d\n", ft_printf("%.2s%.7s\n", "hello", "world"));
	// printf("RETURN: %d\n", printf("%.2s%.7s\n", "hello", "world"));
	// printf("RETURN: %d\n", ft_printf("%.7s%.2s\n", "hello", "world"));
	// printf("RETURN: %d\n", printf("%.7s%.2s\n", "hello", "world"));
	// printf("RETURN: %d\n", ft_printf("MIN s: %s\n p: %p,\n  \n%s\n", buf, &buf,  43));
	// printf("RETURN: %d\n", printf("EMI s: %s\n p: %p,\n \n%s\n", buf,  &buf,  43));
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
