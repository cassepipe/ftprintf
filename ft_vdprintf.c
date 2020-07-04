/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/04 16:06:58 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "header.h"
#include <stdio.h>

static inline int		is_in(char c, const char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

struct Parameters		*parse_specifiers(const char *fs, va_list args)
{
	char flags[] = 		"0- ";
	struct Parameters *format;

	format = malloc(sizeof(struct Parameters));
	if (!format)
		return (NULL);
	format->zero_flag = 0;
	format->minus_flag = 0;
	format->min_field_width = 0;
	format->precision = -1;

	// Flag part
	while (is_in(*fs, flags))
	{
		if (*fs == '0')
			format->zero_flag = 1;
		else if (*fs == '-')
			format->minus_flag = 1;
		fs++;
	}

	// Minimum field with part
	if (*fs == '*')
		format->min_field_width = va_arg(args, int);
	else
		format->min_field_width = ft_atoi(fs);
	while (ft_isdigit(*fs) || *fs == '*')
		fs++;

	// Precision part
	if (*fs == '.')
	{
		fs++;
		if (*fs == '*')
			format->precision = va_arg(args, int);
		else
			format->precision = ft_atoi(fs);
	}
	while (ft_isdigit(*fs) || *fs == '*')
		fs++;

	// Specifier part
	format->type = *fs;

	/*printf("\n\nStruct Parameters :\n");
	printf("format->zero_flag : %s\n", format->zero_flag ? "Yes" : "No");
	printf("format->minus_flag : %s\n", format->minus_flag ? "Yes" : "No");
	printf("format->min_field_width : %d\n", format->min_field_width);
	printf("format->precision : %d\n", format->precision);
	printf("format->type : %c\n", format->type);*/

	return format;
}


char				*write_from_format(int fd, struct Parameters *format, va_list args)
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

	return (replacement);
}

int					ft_vdprintf(int fd, const char *fs, va_list args)
{
	const char specifiers[] = "cspdiuxX%";
	const char flags[] = 		"0123456789- .*";
	struct Parameters *format;
	const char *last_location = fs;

	while (*fs)
	{
		if (*fs == '%')
		{
			fs++;
			format = parse_specifiers(fs, args);
			write_from_format(fd, format, args);
			free(format);
			while (is_in(*fs, flags))
				fs++;
			if (is_in(*fs, specifiers))
				fs++;
			last_location = fs;
		}
		while (*fs && *fs != '%')
			fs++;
		write(fd, last_location, fs - last_location);
	}
	return (0);
}
