/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 13:28:53 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/24 13:31:45 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*duplicate;

	i = 0;
	len = 0;
	while (len < n && s[len])
		len++;
	duplicate = malloc(len + 1);
	if (!duplicate)
		return (NULL);
	while (i < len)
	{
		duplicate[i] = s[i];
		i++;
	}
	duplicate[len] = '\0';
	return (duplicate);
}
