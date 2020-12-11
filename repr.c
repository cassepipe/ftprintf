/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 17:45:47 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/11 15:14:58 by tpouget          ###   ########.fr       */
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

char		*nbr_repr(long nbr, struct s_parameters *format)
{
	char	*str;
	long	diff;
	long	size;
	int		neg;

	neg = nbr < 0 ? 1 : 0;
	nbr = neg ? -nbr : nbr;
	if (format->precision == 0)
		str = ft_strdup("");
	else
		str = ft_lutoa_format(nbr, format->type);
	size = ft_strlen(str);
	if ((diff = format->precision - size) > 0)
		leftpad(&str, '0', diff);
	else if (format->zero_flag
			&& (diff = format->min_field_width - size - neg) > 0)
		leftpad(&str, '0', diff);
	size = ft_strlen(str);
	if (neg && ++size)
		leftpad(&str, '-', 1);
	if (format->minus_flag && (diff = format->min_field_width - size) > 0)
		rightpad(&str, ' ', diff);
	else if ((diff = format->min_field_width - size) > 0)
		leftpad(&str, ' ', diff);
	return (str);
}

char		*str_repr(char *s, struct s_parameters *format)
{
	char	*str;
	long	diff;
	size_t	size;

	format->precision = format->precision < 0 ? INT_MAX : format->precision;
	if (!s)
		str = ft_strndup("(null)", format->precision);
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

char		*char_repr(unsigned char c,
		struct s_parameters *format,
		ssize_t *size)
{
	long	diff;
	int		null_char;
	char	*char_str;

	null_char = 0;
	if (!c && (null_char = 1))
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

char		*ptr_repr(void *ptr, struct s_parameters *format)
{
	char	*ptr_str;
	char	*tmp;
	long	diff;
	size_t	size;

	if (!ptr)
		ptr_str = ft_strdup("0");
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
