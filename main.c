/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frlindh <frlindh@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 10:53:55 by frlindh           #+#    #+#             */
/*   Updated: 2019/10/30 11:28:15 by frlindh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	printf("%020.s]\n", "hej");
	printf("%020.1s]\n", "hej");
	printf("%020-s]\n", "hej");
	printf("%020s]\n", "hej");
	printf("% 32s]\n", "hej");
	printf("%- 022s]\n", "hej");

	printf("%020.c]\n", 'h');
	printf("%020.1c]\n", 'h');
	printf("%020-c]\n", 'h');
	printf("%020c]\n", 'h');
	printf("% 32c]\n", 'h');
	printf("%- 022c]\n", 'h');
	return 0;
}
