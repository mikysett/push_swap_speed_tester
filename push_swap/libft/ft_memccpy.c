/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:26:56 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 11:52:15 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	c = (unsigned char)c;
	if (dest != src)
	{
		while (n > 0)
		{
			*((unsigned char *)dest++) = *((unsigned char *)src++);
			if (*((unsigned char *)src - 1) == c)
				return (dest);
			n--;
		}
	}
	return (0);
}
