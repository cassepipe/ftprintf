/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leftpad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 10:31:16 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/25 16:49:28 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	leftpad(char **str, char c, size_t n)
{
	char *tmp;
	char padding[++n];

	padding[--n] = '\0';
	while (--n)
		padding[n] = c;
	padding[0] = c;

	tmp = *str;
	*str = ft_strjoin(padding, *str);
	free(tmp);
}

void	rightpad(char **str, char c, size_t n)
{
	char *tmp;
	char padding[++n];

	padding[--n] = '\0';
	while (--n)
		padding[n] = c;
	padding[0] = c;

	tmp = *str;
	*str = ft_strjoin(*str, padding);
	free(tmp);
}
