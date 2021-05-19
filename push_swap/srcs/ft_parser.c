/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:59:04 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 16:43:42 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

// bool	ft_duplicated_nb(t_stack *s_a)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	printf("Check duplicated starts\n");
// 	while (i < s_a->size)
// 	{
// 		j = i + 1;
// 		while (j < s_a->size)
// 		{
// 			if (s_a->stack[i].nb == s_a->stack[j].nb)
// 				return (true);
// 			j++;
// 		}
// 		i++;
// 	}
// 	printf("Check duplicated completed\n");
// 	return (false);
// }

// bool	ft_duplicated_nb(t_stack *s_a)
// {
// 	char	*pos_hash;
// 	char	*neg_hash;
// 	int		i;
// 	int		curr_nb;

// 	printf("CHECK DUPLICATES starts\n");
// 	pos_hash = ft_calloc(INT_MAX + (size_t)1, sizeof(char));
// 	neg_hash = ft_calloc(INT_MAX + (size_t)1, sizeof(char));
// 	if (!pos_hash || !neg_hash)
// 		return (true);
// 	i = 0;
// 	while (i < s_a->size)
// 	{
// 		curr_nb = s_a->stack[i].nb;
// 		if (curr_nb >= 0)
// 		{
// 			if (pos_hash[curr_nb])
// 				break;
// 			pos_hash[curr_nb] = 1;
// 		}
// 		else
// 		{
// 			if (neg_hash[curr_nb + INT_MAX + 1])
// 				break;
// 			neg_hash[curr_nb + INT_MAX + 1] = 1;
// 		}
// 		i++;
// 	}
// 	free(pos_hash);
// 	free(neg_hash);
// 	printf("Check duplicated completed\n");
// 	if (i != s_a->size)
// 		return (true);
// 	return (false);
// }

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