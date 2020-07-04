/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_repr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:08:45 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/04 16:00:52 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ptr_repr(void *ptr, struct Parameters *format)
{
	char *ptr_str;
	char *tmp;
	long diff;
	size_t size;

	if (!ptr)
		ptr_str = ft_strdup("0x0");
	else
		ptr_str = ft_lutoa_base((unsigned long)ptr, "0123456789abcdef");
	tmp = ptr_str;
	ptr_str = ft_strjoin("0x", ptr_str);
	free(tmp);
	size = ft_strlen(ptr_str);
	if ((diff = format->min_field_width - size) > 0)
	{
		if (format->minus_flag)
			rightpad(&ptr_str, ' ', diff);
		else if (format->zero_flag)
			leftpad(&ptr_str, '0', diff);
		else
			leftpad(&ptr_str, ' ', diff);
	}

	return (ptr_str);
}
