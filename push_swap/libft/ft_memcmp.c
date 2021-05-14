/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 00:20:58 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 11:52:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- > 0)
		if (*((unsigned char *)s1++) != *((unsigned char *)s2++))
			return (*((unsigned char *)s1 - 1) - *((unsigned char *)s2 - 1));
	return (0);
}
