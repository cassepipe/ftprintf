/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:44:49 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/13 19:40:35 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int main(void)
{
	//char *ptr = malloc(1);
	//char *null = NULL;

	/*printf("%.5s%7s\n", "yo", "boi");*/
	/*ft_printf("%.5s%7s\n", "yo", "boi");*/

	/*printf("%3.7s%7.7s\n", "hello", "world");*/
	/*ft_printf("%3.7s%7.7s\n", "hello", "world");*/

	/*printf("%3.3s%7.7s\n", "hello", "world");*/
	/*ft_printf("%3.3s%7.7s\n", "hello", "world");*/

	/*printf("%3.7s%7.3s\n", "hello", "world");*/
	/*ft_printf("%3.7s%7.3s\n", "hello", "world");*/

	/*printf("%3.3s%7.3s\n", "hello", "world");*/
	/*ft_printf("%3.3s%7.3s\n", "hello", "world");*/

	/*printf("%32s\n", NULL);*/
	/*ft_printf("%32s\n", NULL);*/

	/*printf("%-32s\n", NULL);*/
	/*ft_printf("%-32s\n", NULL);*/

	/*printf("%-16s\n", NULL);*/
	/*ft_printf("%-16s\n", NULL);*/

	/*printf("%.03s\n", NULL);*/
	/*ft_printf("%.03s\n", NULL);*/

	/*printf("%3.s\n", NULL);*/
	/*ft_printf("%3.s\n", NULL);*/

	/*printf("%10.s\n", NULL);*/
	/*ft_printf("%10.s\n", NULL);*/

	/*printf("%-3.s\n", NULL);*/
	/*ft_printf("%-3.s\n", NULL);*/

	/*printf("%-8.s\n", NULL);*/
	/*ft_printf("%-8.s\n", NULL);*/

	/*printf("%3.1s\n", NULL);*/
	/*ft_printf("%3.1s\n", NULL);*/

	/*printf("%9.1s\n", NULL);*/
	/*ft_printf("%9.1s\n", NULL);*/

	/*[>printf("%s\n", NULL);<]*/
	/*[>ft_printf("%s\n", NULL);<]*/

	/*printf("%-9.1s\n", NULL);*/
	/*ft_printf("%-9.1s\n", NULL);*/

	/*printf("%20.6s\n", NULL);*/
	/*ft_printf("%20.6s\n", NULL);*/

	/*printf("%-10.8s\n", NULL);*/
	/*ft_printf("%-10.8s\n", NULL);*/

	/*printf("%16s\n", "nark nark");*/
	/*ft_printf("%16s\n", "nark nark");*/

	/*printf("%-16s\n", "nark nark");*/
	/*ft_printf("%-16s\n", "nark nark");*/

	/*printf("%c\n", '\0');*/
	/*ft_printf("%c\n", '\0');*/

	/*printf("%5c\n", '\0');*/
	/*ft_printf("%5c\n", '\0');*/

	/*printf("%-5c\n", '\0');*/
	/*ft_printf("%-5c\n", '\0');*/

	/*printf("%04d\n", -532);*/
	/*ft_printf("%04d\n", -532);*/

	/*printf("%-3.7i\n", 3267);*/
	/*ft_printf("%-3.7i\n", 3267);*/

	/*printf("%0*i\n", -7, -54);*/
	/*ft_printf("%0*i\n", -7, -54);*/

	/*printf("%.3d\n", 0);*/
	/*ft_printf("%.3d\n", 0);*/

	/*printf("%08.5i\n", 0);*/
	/*ft_printf("%08.5i\n", 0);*/

	/*printf("%*d\n", -2147483648, 12345);*/
	/*ft_printf("%*d\n", -2147483648 , 12345);*/

	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	/*printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12*/
	/*ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", i, j, k, l, m, c, e, d); //T12*/

	/*printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d); //T13*/
	/*ft_printf("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d, %.0d\n", i, j, k, l, m, c, e, d); //T13*/

	/*printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d\n", i, j, k, l, m, c, e, d); //T14*/
	/*ft_printf("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d\n", i, j, k, l, m, c, e, d); //T14*/

	printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", 0, 0, 0, 0, 0, 0, 0, 0); //T12
	ft_printf("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d, %0.d\n", 0, 0, 0, 0, 0, 0, 0, 0); //T12

	return(0);

}
