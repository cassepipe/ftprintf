/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_repr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:35:08 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/04 15:34:15 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*ft_lutoa_format(long nbr, int type)
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

char	*nbr_repr(long nbr, struct Parameters *format)
{
	char *str;
	ssize_t diff;
	size_t size;
	int neg;

	neg = nbr < 0 ? 1 : 0;
	nbr = neg ? -nbr : nbr;
	if (format->precision == 0)
		str = ft_strdup("");
	else
		str = ft_lutoa_format(nbr, format->type);

	size = ft_strlen(str);
	if (format->precision > 0)
	{
		diff = format->precision - size;
		if (diff > 0)
			leftpad(&str, '0', diff);
	}
	else if (format->zero_flag && !format->minus_flag)
	{
		diff = format->min_field_width - size;
		if (diff > 0)
		{
			leftpad(&str, '0', diff);
			if (neg)
			{
				*str = '-';
				neg--;
			}
		}
	}
	size = ft_strlen(str);
	if (neg)
	{
		leftpad(&str, '-', 1);
		size++;
	}
	if(format->minus_flag)
	{
		diff = format->min_field_width - size;
		if (diff > 0)
			rightpad(&str, ' ', diff);
	}
	else
	{
		diff = format->min_field_width - size;
		if (diff > 0)
			leftpad(&str, ' ', diff);
	}
	return (str);
}
