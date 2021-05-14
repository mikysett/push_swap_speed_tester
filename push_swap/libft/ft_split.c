/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:26:17 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 12:49:33 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_strs(char const *s, char c)
{
	int	nb_s;

	if (!*s)
		return (0);
	s++;
	nb_s = 0;
	while (*s)
	{
		if (*s == c && *(s - 1) != c)
		{
			nb_s++;
			s++;
			if (!*s)
				break ;
		}
		s++;
	}
	if (*(s - 1) != c)
		return (nb_s + 1);
	return (nb_s);
}

static int	ft_set_strs_size(char **res, char const *str, char c)
{
	size_t	s_size;

	s_size = 0;
	while (*str)
	{
		if (*str != c)
			s_size++;
		else if (s_size != 0)
		{
			*res = malloc(sizeof(char) * (s_size + 1));
			if (!*res)
				return (0);
			res++;
			s_size = 0;
		}
		str++;
	}
	if (s_size != 0)
	{
		*res = malloc(sizeof(char) * (s_size + 1));
		if (!*res)
			return (0);
	}
	return (1);
}

static void	ft_cpy_strs(char **strs, char const *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s != c)
			(*strs)[j++] = *s;
		else if (j != 0)
		{
			(*(strs++))[j] = '\0';
			j = 0;
		}
		s++;
	}
	if (j != 0)
	{
		(*strs)[j] = '\0';
		strs++;
	}
	*strs = 0;
}

static char	**ft_free_exit(char **res)
{
	int	i;

	if (res)
	{
		i = 0;
		while (res[i])
		{
			free(res[i]);
			i++;
		}
		free(res);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		nb_strs;
	char	**res;

	if (!s)
		return (0);
	if (c)
		while (*s == c)
			s++;
	nb_strs = ft_nb_strs(s, c);
	res = malloc(sizeof(char *) * (nb_strs + 1));
	if (!res)
		return (0);
	if (nb_strs)
		if (!ft_set_strs_size(res, s, c))
			return (ft_free_exit(res));
	ft_cpy_strs(res, s, c);
	return (res);
}
