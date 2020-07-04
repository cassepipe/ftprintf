/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_repr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 20:47:21 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/04 12:52:01 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*static char *find_and_replace(char** str, char old, char new)
{
	while (**str)
	{
		if (**str == old)
			**str = new;
		(*str)++;
	}
	return (*str);
}*/

char	*char_repr(unsigned char c, struct Parameters *format, ssize_t *size)
{
	long diff;
	int null_char;
	char *char_str;

	null_char = 0;
	if(!c && (null_char = 1))
		c = 1;
	if (!(char_str = malloc(2)))
		return (NULL);
	char_str[0] = c;
	char_str[1] = '\0';
	if ((diff = format->min_field_width - 1) > 0)
	{
		if (format->minus_flag)
			rightpad(&char_str, ' ', diff);
		else if (format->zero_flag)
			leftpad(&char_str, '0', diff);
		else
			leftpad(&char_str, ' ', diff);
	}
	*size = ft_strlen(char_str);
	diff = -1;
	if (null_char)
		while (char_str[++diff])
			if (char_str[diff] == 1)
				char_str[diff] = '\0';
	return (char_str);
}
