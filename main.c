/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:44:49 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/03 12:23:27 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int main(void)
{
	//char *ptr = malloc(1);
	//char *null = NULL;


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

//	printf("%.03s\n", NULL);
//	ft_printf("%.03s\n", NULL);

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

	printf("%s\n", NULL);
	ft_printf("%s\n", NULL);

	/*printf("%-9.1s\n", NULL);*/
	/*ft_printf("%-9.1s\n", NULL);*/

	/*printf("%20.6s\n", NULL);*/
	/*ft_printf("%20.6s\n", NULL);*/

	/*printf("%-10.8s\n", NULL);*/
	/*ft_printf("%-10.8s\n", NULL);*/

	printf("%16s\n", "nark nark");
	ft_printf("%16s\n", "nark nark");

	printf("%-16s\n", "nark nark");
	ft_printf("%-16s\n", "nark nark");

}
