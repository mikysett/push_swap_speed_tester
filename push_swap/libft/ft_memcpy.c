/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:07:54 by msessa            #+#    #+#             */
/*   Updated: 2021/02/15 19:05:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*res;

	res = dest;
	if (dest != src)
		while (n-- > 0)
			*((unsigned char *)dest++) = *((unsigned char *)src++);
	return (res);
}
