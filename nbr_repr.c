/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_repr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 17:35:08 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/25 15:54:02 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*nbr_repr(int nbr, struct Parameters *format)
{
	char *str;
	ssize_t diff;
	size_t size;

	if (format->type == 'd' || format->type == 'i')
		str = ft_itoa(nbr);
	else if (format->type == 'u')
		str = ft_lutoa_base(nbr, "0123456789");
	else if (format->type == 'x')
		str = ft_lutoa_base(nbr, "0123456789abcdef");
	else if (format->type == 'X')
		str = ft_lutoa_base(nbr, "0123456789ABCDEF");
	size = ft_strlen(str);
	if ((diff = format->precision - size) > 0)
		leftpad(&str, '0', diff);
	size = ft_strlen(str);
	if ((diff = format->min_field_width - size) > 0)
	{
		if (format->minus_flag)
		{
			rightpad(&str, ' ', diff);
		}
		else if (format->precision < 0 && format->zero_flag)
		{
			leftpad(&str, '0', diff);
		}
		else
		{
			leftpad(&str, ' ', diff);
		}
	}
	/*printf("nbr=%s and out !\n", str);*/
	if (!str)
		return ("(allocation error)");
	return (str);
}
