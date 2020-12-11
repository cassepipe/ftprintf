/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 17:04:37 by tpouget           #+#    #+#             */
/*   Updated: 2020/12/11 22:36:33 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*joined;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !*s1)
		return (ft_strdup(s2));
	if (!s2 || !*s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(joined = malloc(len + 1)))
		return (NULL);
	ft_strlcpy(joined, s1, len + 1);
	ft_strlcat(joined, s2, len + 1);
	return (joined);
}
