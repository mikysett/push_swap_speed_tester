/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:44:50 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 13:11:49 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_copystr(char const *s, size_t s_len)
{
	char	*res;

	res = malloc(sizeof(char) * (s_len + 1));
	if (!res)
		return (0);
	res[s_len] = '\0';
	while (s_len-- > 0)
		res[s_len] = s[s_len];
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len < start)
	{
		s += s_len;
		s_len = 0;
	}
	else
	{
		s += start;
		s_len -= start;
		if (s_len > len)
			s_len = len;
	}
	return (ft_copystr(s, s_len));
}
