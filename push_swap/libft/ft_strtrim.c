/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:19:49 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 12:50:42 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char const c, char const *set)
{
	while (c != *set && *set)
		set++;
	if (*set)
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*res;
	char	*ores;

	if (!s1 || !set)
		return (0);
	end = ft_strlen(s1);
	start = 0;
	while (ft_isinset(*(s1 + end - 1), set) && end != 0)
		end--;
	while (ft_isinset(*(s1 + start), set) && start < end)
		start++;
	res = malloc(sizeof(char) * (end - start + 1));
	if (!res)
		return (0);
	ores = res;
	while (start < end)
		*res++ = s1[start++];
	*res = '\0';
	return (ores);
}
