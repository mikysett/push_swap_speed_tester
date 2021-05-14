/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:33:19 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 17:45:15 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

bool	ft_init_stacks(int argc, char **argv, t_stack *stacks)
{
	int	i;
	int	j;

	j = 1;
	i = argc - 1;
	stacks[s_a].size = i;
	stacks[s_b].size = 0;
	stacks[s_a].stack = malloc(sizeof(int) * i);
	stacks[s_b].stack = malloc(sizeof(int) * i);
	if (!stacks[s_a].stack || !stacks[s_a].stack)
		return (false);
	while (--i >= 0)
	{
		stacks[s_a].stack[i] = ft_atoi(argv[j]);
		j++;
	}
	return (true);
}
