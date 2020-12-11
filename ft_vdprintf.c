/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/11 22:19:01 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

static inline int			is_in(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static void					*init_format(struct s_parameters *format)
{
	format->zero_flag = 0;
	format->minus_flag = 0;
	format->min_field_width = 0;
	format->precision = -1;
	return (format);
}

static void					arrange_format(struct s_parameters *format)
{
	if (format->min_field_width == INT_MIN)
		format->min_field_width++;
	if (format->min_field_width < 0)
	{
		format->min_field_width = -format->min_field_width;
		format->minus_flag = 1;
	}
	if (format->minus_flag)
		format->zero_flag = 0;
	if (format->precision >= 0 && is_in(format->type, "diuxX"))
		format->zero_flag = 0;
}

static void					*parse_str_into_format(const char *fs,
		struct s_parameters *format,
		va_list args)
{
	while (is_in(*fs, FLAGS))
	{
		if (*fs == '0')
			format->zero_flag = 1;
		else if (*fs == '-')
			format->minus_flag = 1;
		fs++;
	}
	if (*fs == '*')
		format->min_field_width = va_arg(args, int);
	else
		format->min_field_width = ft_atoi(fs);
	while (ft_isdigit(*fs) || *fs == '*')
		fs++;
	if (*fs == '.' && fs++)
	{
		if (*fs == '*')
			format->precision = va_arg(args, int);
		else
			format->precision = ft_atoi(fs);
	}
	while (ft_isdigit(*fs) || *fs == '*')
		fs++;
	format->type = *fs;
	return (format);
}

static void					write_from_format(int fd,
		struct s_parameters *format,
		va_list args)
{
	char	*replacement;
	ssize_t	size;

	size = -1;
	if (is_in(format->type, "di"))
		replacement = nbr_repr(va_arg(args, int), format);
	else if (is_in(format->type, "uxX"))
		replacement = nbr_repr(va_arg(args, unsigned int), format);
	else if (format->type == 's')
		replacement = str_repr(va_arg(args, char*), format);
	else if (format->type == 'c')
		replacement = char_repr(va_arg(args, int), format, &size);
	else if (format->type == 'p')
		replacement = ptr_repr(va_arg(args, void*), format);
	else if (format->type == '%')
		replacement = str_repr("%", format);
	else
		replacement = ft_strdup("(format error)");
	if (size < 0)
		size = ft_strlen(replacement);
	if (replacement)
		write(fd, replacement, size);
	free(replacement);
}

int						ft_vdprintf(int fd, const char *fs, va_list args)
{
	struct s_parameters	format;
	const char			*last_location;

	last_location = fs;
	while (*fs)
	{
		if (*fs == '%')
		{
			fs++;
			init_format(&format);
			parse_str_into_format(fs, &format, args);
			arrange_format(&format);
			write_from_format(fd, &format, args);
			while (is_in(*fs, "0123456789- .*"))
				fs++;
			if (is_in(*fs, "cspdiuxX%"))
				fs++;
			last_location = fs;
		}
		while (*fs && *fs != '%')
			fs++;
		write(fd, last_location, fs - last_location);
	}
	return (0);
}
