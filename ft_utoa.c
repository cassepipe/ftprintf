/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpouget <cassepipe@ymail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 21:00:01 by tpouget           #+#    #+#             */
/*   Updated: 2020/06/21 16:27:31 by tpouget          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static unsigned long	ft_10powerof(unsigned long n)
{
	long result;

	result = 1;
	while (n--)
		result *= 10;
	return (result);
}

char		*ft_utoa(unsigned int n)
{
	unsigned long	nbr;
	unsigned long	digit;
	unsigned long	i;
	long			pos;
	char			*result;

	nbr = n;
	pos = 1;
	i = nbr;
	while (i /= 10)
		pos++;
	result = malloc(pos + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (--pos >= 0)
	{
		digit = nbr / ft_10powerof(pos);
		result[i++] = digit + '0';
		nbr = nbr - digit * ft_10powerof(pos);
	}
	result[i] = '\0';
	return (result);
}
