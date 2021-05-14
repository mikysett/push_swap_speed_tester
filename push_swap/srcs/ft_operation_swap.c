/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_swap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:02:41 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 18:21:27 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

static bool	ft_swap(t_stack *s)
{
	int	top;
	int	buf;

	if (s->size < 2)
		return (false);
	top = s->size - 1;
	buf = s->stack[top];
	s->stack[top] =  s->stack[top - 1];
	s->stack[top - 1] = buf;
	return (true);
}

void	ft_swap_a(t_stack *stacks)
{
	if (ft_swap(&stacks[s_a]))
		write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *stacks)
{
	if (ft_swap(&stacks[s_b]))
		write(1, "sb\n", 3);
}

void	ft_swap_2(t_stack *stacks)
{
	if (ft_swap(&stacks[s_a]) || ft_swap(&stacks[s_b]))
		write(1, "ss\n", 3);
}
