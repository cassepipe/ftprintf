/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_repr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:19:58 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/03 14:52:58 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *str_repr(char *s, struct Parameters *format)
{
	char *str;
	ssize_t diff;
	size_t size;

	format->precision = format->precision < 0 ? INT_MAX : format->precision;
	if (!s)
		str = ft_strndup("(null)", format->precision);
	else  if (format->type == 'c')
		str = ft_strndup(s, 1);
	else
		str = ft_strndup(s, format->precision);
	size = ft_strlen(str);
	if ((diff = format->min_field_width - size) > 0)
	{
		if (format->minus_flag)
			rightpad(&str, ' ', diff);
		else if (format->zero_flag)
			leftpad(&str, '0', diff);
		else
			leftpad(&str, ' ', diff);
	}
	return (str);
}
