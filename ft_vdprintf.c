/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vdprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:18:09 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/12 23:22:03 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int						ft_vdprintf(int fd, const char *fs, va_list args)
{
	struct s_parameters	format;
	const char			*last_loc;
	ssize_t				ret;
	ssize_t				sz;

	ret = 0;
	last_loc = fs;
	while (*fs)
	{
		if (*fs == '%' && fs++)
		{
			init_format(&format);
			parse_str_into_format(fs, &format, args);
			if ((sz = write_formatted(fd, args, &format)) == -1 || !(ret += sz))
				return (-1);
			while (is_in(*fs, "0123456789- .*"))
				fs++;
			last_loc = ++fs;
		}
		while (*fs && *fs != '%')
			fs++;
		if ((sz = write(fd, last_loc, fs - last_loc)) == -1 || !(ret += sz))
			return (-1);
	}
	return (ret);
}
