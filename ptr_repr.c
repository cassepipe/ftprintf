/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_repr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:08:45 by tpouget           #+#    #+#             */
/*   Updated: 2020/07/04 15:38:40 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

char	*ptr_repr(void *ptr)
{
	char *p;
	char *tmp;

	if (!ptr)
		return (ft_strdup("(nil)"));
	p = ft_lutoa_base((unsigned long)ptr, "0123456789abcdef");
	tmp = p;
	p = ft_strjoin("0x", p);
	free(tmp);
	if (!p)
		return ("(allocation error)");
	return (p);
}

