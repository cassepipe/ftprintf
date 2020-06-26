/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/23 12:25:20 by tpouget          ###   ########.fr       */
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
	char specifiers[] = "cspdiuxX";
	struct Parameters *format;

	format = malloc(sizeof(struct Parameters));
	if (!format)
		return (NULL);
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
	while (ft_isdigit(*fs))
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
	while (ft_isdigit(*fs))
		fs++;

	// Specifier part
	if (is_in(*fs, specifiers))
		format->type = *fs;

	/*printf("\n\nStruct Parameters :\n");
	  printf("format->padding_flag : %s\n", format->padding_flag ? "Yes" : "No");
	  printf("format->right_adjust_flag : %s\n", format->right_adjust_flag ? "Yes" : "No");
	  printf("format->min_field_width : %d\n", format->min_field_width);
	  printf("format->precison : %d\n", format->padding_flag);
	  printf("format->type : %c\n", format->type);
	*/

	return format;
}


char				*write_from_format(int fd, struct Parameters *format, va_list args)
{
	char *replacement;
	char c;

	if 		(is_in(format->type, "diuxX"))
		replacement = nbr_repr(va_arg(args, int), format);
	else if (format->type == 's')
		replacement = str_repr(va_arg(args, char*), format);
	else if (format->type == 'c' && (c = va_arg(args, int)))
		replacement = str_repr(&c, format);
	else if (format->type == 'p')
		replacement = ptr_repr(va_arg(args, void*));
	else if (format->type == '%' && (c = '%'))
		replacement = str_repr(&c, format);
	else
		replacement = ft_strdup("(format error)");

	write(fd, replacement, ft_strlen(replacement));

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
