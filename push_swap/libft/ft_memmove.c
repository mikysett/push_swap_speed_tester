/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:32:01 by msessa            #+#    #+#             */
/*   Updated: 2021/02/18 12:09:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src)
		return (dest);
	else if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	else if (n > 0)
	{
		i = n;
		while (--i != 0)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	}
	return (dest);
}
