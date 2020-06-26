/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_repr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 18:19:58 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/22 18:27:45 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char *str_repr(char *s, struct Parameters *format)
{
	char *str;
	char *old;
	char *padding;
	ssize_t diff;
	size_t size;

	if (!s)
		return (ft_strdup("(null)"));
	if (format->type == 'c')
		str = ft_strndup(s, 1);
	else
		str = ft_strndup(s, format->precision);
	size = ft_strlen(str);
	if ((diff = format->min_field_width - size) > 0)
	{
		padding = malloc(diff);
		if (format->zero_flag && !format->minus_flag)
			ft_memset(padding, '0', diff);
		else
			ft_memset(padding, ' ', diff);
		old = str;
		if (format->minus_flag)
			str= ft_strjoin(str, padding);
		else
			str = ft_strjoin(padding, str);
		free(old);
	}
	return (str);
}
