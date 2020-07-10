/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/10 17:23:36 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

int	ft_printf(const char *formatted_string, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, formatted_string);
	ret = ft_vdprintf(STDOUT_FILENO, formatted_string, ap);
	va_end(ap);
	return (ret);
}
