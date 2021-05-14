/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:59:04 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 17:37:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

bool	ft_duplicated_nb(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (stack_a->stack[i] == stack_a->stack[j])
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

static bool	ft_isnumber(char *nb)
{
	if (*nb == '-')
		nb++;
	if (!*nb)
		return (false);
	while (*nb)
	{
		if (*nb < '0' || *nb > '9')
			return (false);
		nb++;
	}
	return (true);
}

static bool	ft_isint(char *nb)
{
	size_t	nb_size;
	char	*nb_char;

	nb_size = ft_strlen(nb);
	nb_char = ft_itoa(ft_atoi(nb));
	if (nb_size != ft_strlen(nb_char)
		|| ft_strncmp(nb, nb_char, nb_size))
	{
		free(nb_char);
		return (false);
	}
	free(nb_char);
	return (true);
}

bool	ft_parser(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isnumber(argv[i]) || !ft_isint(argv[i]))
			return (false);
		i++;
	}
	return (true);
}