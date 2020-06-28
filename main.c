/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 12:44:49 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/27 20:41:02 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int main(void)
{
	char *ptr = malloc(1);
	char *null = NULL;

	ft_printf("Hello my name is %10.5i and I am %3d years old\n", 255, 0);
	   printf("Hello my name is %10.5i and I am %3d years old\n", 255, 0);
}
