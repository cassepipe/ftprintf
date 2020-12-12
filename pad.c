/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pad.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/23 10:31:16 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/12 19:47:12 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*leftpad(char **str, char c, size_t n)
{
	char	*padding;
	char	*tmp;

	padding = malloc(n);
	padding[--n] = '\0';
	while (--n >= 0)
		padding[n] = c;
	tmp = *str;
	*str = ft_strjoin(padding, *str);
	free(tmp);
	return (*str);
}

char	*rightpad(char **str, char c, size_t n)
{
	char	*padding;
	char	*tmp;

	padding = malloc(n);
	padding[--n] = '\0';
	while (--n >= 0)
		padding[n] = c;
	tmp = *str;
	*str = ft_strjoin(*str, padding);
	free(tmp);
	return (*str);
}
