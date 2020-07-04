/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 11:20:06 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/04 17:57:23 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H 

# define INT_MAX 2147483647 
# define INT_MIN -2147483648 
# define FLAGS "0- "

# include <unistd.h> 
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

struct	Parameters {
	int	zero_flag;
	int	minus_flag;
	int	min_field_width;
	int	precision;
	int	type;
};

int		ft_printf(const char *, ...);
int		ft_dprintf(int fd, const char *, ...);
int		ft_vdprintf(int fd, const char *, va_list);

char	*ft_utoa(unsigned int n);
char	*ft_utoa_base(unsigned int n, const char *base);
char	*ptr_repr(void* ptr, struct Parameters *format);	
char	*str_repr(char* str, struct Parameters *format);
char	*nbr_repr(long nbr, struct Parameters* format);
char	*char_repr(unsigned char c, struct Parameters *format, ssize_t *size);
void	leftpad(char **str, char c, size_t n);
void	rightpad(char **str, char c, size_t n);

#endif
