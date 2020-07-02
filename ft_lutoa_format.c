/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lutoa_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:51:13 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/29 17:55:33 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_utoa_format(int nbr, int type)
{
	char *str;

	if (type == 'u' || type == 'd' || type == 'i')
		str = ft_lutoa_base(nbr, "0123456789");
	else if (type == 'x')
		str = ft_lutoa_base(nbr, "0123456789abcdef");
	else if (type == 'X')
		str = ft_lutoa_base(nbr, "0123456789ABCDEF");
	else
		str = "(unknown format)";

	return (str);
}
