/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:13:38 by msessa            #+#    #+#             */
/*   Updated: 2021/02/16 11:17:33 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*odst;
	size_t	dst_len;
	size_t	src_len;

	odst = dst;
	while (*dst && size != 0)
	{
		dst++;
		size--;
	}
	dst_len = dst - odst;
	src_len = ft_strlen(src);
	if (size == 0)
		return (dst_len + src_len);
	size--;
	while (*src && size != 0)
	{
		*dst++ = *src++;
		size--;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
