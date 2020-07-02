/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:44:49 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/02 15:41:49 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int main(void)
{
	//char *ptr = malloc(1);
	//char *null = NULL;

/*
	printf("Hello my name is %10.5i and I am %3d years old\n", 255, 0);
	ft_printf("Hello my name is %10.5i and I am %3i years old\n", 255, 0);

	printf("%3d\n", 0);
	ft_printf("%3d\n", 0);

	printf("%.6i\n", -3);
	ft_printf("%.6i\n", -3);

	printf("%7u\n", 33);
	ft_printf("%7u\n", 33);

	printf("%07i\n", -54);
	ft_printf("%07i\n", -54);

	printf("%05i\n", 43);
	ft_printf("%05i\n", 43);

	printf("%.*u\n", -3, 12345);
	ft_printf("%.*u\n", -3, 12345);

	printf("%u\n", 4294967295);
	ft_printf("%u\n", 4294967295);

	printf("%%\n");
	ft_printf("%%\n");*/


	printf("%.5s%7s\n", "yo", "boi");
	ft_printf("%.5s%7s\n", "yo", "boi");

	printf("%3.7s%7.7s\n", "hello", "world");
	ft_printf("%3.7s%7.7s\n", "hello", "world");

	printf("%3.3s%7.7s\n", "hello", "world");
	ft_printf("%3.3s%7.7s\n", "hello", "world");

	printf("%3.7s%7.3s\n", "hello", "world");
	ft_printf("%3.7s%7.3s\n", "hello", "world");

	printf("%3.3s%7.3s\n", "hello", "world");
	ft_printf("%3.3s%7.3s\n", "hello", "world");

	printf("%32s\n", NULL);
	ft_printf("%32s\n", NULL);

	printf("%-32s\n", NULL);
	ft_printf("%-32s\n", NULL);

	printf("%-16s\n", NULL);
	ft_printf("%-16s\n", NULL);

	printf("%.03s\n", NULL);
	ft_printf("%.03s\n", NULL);

	printf("%3.s\n", NULL);
	ft_printf("%3.s\n", NULL);

	printf("%10.s\n", NULL);
	ft_printf("%10.s\n", NULL);

	printf("%-3.s\n", NULL);
	ft_printf("%-3.s\n", NULL);

	printf("%-8.s\n", NULL);
	ft_printf("%-8.s\n", NULL);

	printf("%3.1s\n", NULL);
	ft_printf("%3.1s\n", NULL);

	printf("%9.1s\n", NULL);
	ft_printf("%9.1s\n", NULL);

	printf("%-3.1s\n", NULL);
	ft_printf("%-3.1s\n", NULL);

	printf("%-9.1s\n", NULL);
	ft_printf("%-9.1s\n", NULL);

	printf("%20.6s\n", NULL);
	ft_printf("%20.6s\n", NULL);

	printf("%-10.8s\n", NULL);
	ft_printf("%-10.8s\n", NULL);
}
