/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:29:25 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/10 17:21:32 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_dprintf(int fd, const char *formatted_string, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, formatted_string);
	ret = ft_vdprintf(fd, formatted_string, ap);
	va_end(ap);
	return (ret);
}
