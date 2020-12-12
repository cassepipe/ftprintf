/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:20:06 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/12 23:05:50 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define FLAGS "0- "

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

struct	s_parameters {
	int	zero_flag;
	int	minus_flag;
	int	min_field_width;
	int	precision;
	int	type;
};

int		ft_printf(const char *formatted_string, ...);
int		ft_dprintf(int fd, const char *formatted_string, ...);
int		ft_vdprintf(int fd, const char *formatted_string, va_list arg_list);

char	*ft_lutoa_base(unsigned long n, const char *base);
char	*ptr_repr(void *ptr, struct s_parameters *format, ssize_t *size);
char	*str_repr(char *str, struct s_parameters *format, ssize_t *size);
char	*nbr_repr(long nbr, struct s_parameters	*format, ssize_t *size);
char	*char_repr(unsigned char c, struct s_parameters *format, ssize_t *size);
void	leftpad(char **str, char c, size_t n);
void	rightpad(char **str, char c, size_t n);

int		is_in(char c, const char *charset);
void	init_format(struct s_parameters *format);
void	arrange_format(struct s_parameters *format);
void	*parse_str_into_format(const char *fs, struct s_parameters *format,
																va_list args);
ssize_t	write_formatted(int fd, va_list args, struct s_parameters *format);
int		ft_vdprintf(int fd, const char *fs, va_list args);

#endif
