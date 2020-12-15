/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:44:49 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/15 14:08:56 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int main(void)
{
	char *ptr = malloc(1);
	char *null = NULL;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;


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

	printf("%-9.1s\n", NULL);
	ft_printf("%-9.1s\n", NULL);

	printf("%20.6s\n", NULL);
	ft_printf("%20.6s\n", NULL);

	printf("%-10.8s\n", NULL);
	ft_printf("%-10.8s\n", NULL);

	printf("%16s\n", "nark nark");
	ft_printf("%16s\n", "nark nark");

	printf("%-16s\n", "nark nark");
	ft_printf("%-16s\n", "nark nark");

	printf("%c\n", '\0');
	ft_printf("%c\n", '\0');

	printf("%5c\n", '\0');
	ft_printf("%5c\n", '\0');

	printf("%-5c\n", '\0');
	ft_printf("%-5c\n", '\0');

	printf("%04d\n", -532);
	ft_printf("%04d\n", -532);

	printf("%-3.7i\n", 3267);
	ft_printf("%-3.7i\n", 3267);

	printf("%0*i\n", -7, -54);
	ft_printf("%0*i\n", -7, -54);

	printf("%.3d\n", 0);
	ft_printf("%.3d\n", 0);

	printf("%08.5i\n", 0);
	ft_printf("%08.5i\n", 0);

	printf("(null)\n", (char)(0));
	ft_printf("(null)\n", (char)(0));


	printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12
	ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12

	printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", 0, 0, 0, 0, 0, 0, 0, 0); //T12
	ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", 0, 0, 0, 0, 0, 0, 0, 0); //T12


	i = printf("\\!/%-2lc\\!/", (char)200);
	puts("");
	printf("Returned = %d\n", i);
	j = ft_printf("\\!/%-2lc\\!/", (char)200);
	puts("");
	printf("Returned = %d\n", j);

	i = printf("This should not print any further %k than there\n", 123);
	printf("Returned = %d\n", j);
	i = ft_printf("This should not print any further %k than there\n", 123);
	printf("Returned = %d\n", j);

	/*The real printf makes a infinite loop on this one*/
	/*i = printf("%*d\n", -2147483648, 12345);*/
	/*printf("Returned = %d\n", i);*/
	/*i = ft_printf("%*d\n", -2147483648 , 12345);*/
	/*printf("Returned = %d\n", i);*/

	/*The real printf crashes on this one*/
	/*printf("%s\n", NULL);*/
	/*ft_printf("%s\n", NULL);*/

	free(ptr);
	return(0);

}
