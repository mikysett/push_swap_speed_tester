/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:02:41 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 18:56:09 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

static bool	ft_reverse_rotate(t_stack *s)
{
	int i;
	int	top;
	int	buf;

	if (s->size < 2)
		return (false);
	i = 1;
	top = s->size - 1;
	buf = s->stack[0];
	while (i <= top)
	{
		s->stack[i - 1] = s->stack[i];
		i++;
	}
	s->stack[top] = buf;
	return (true);
}

void	ft_reverse_rotate_a(t_stack *stacks)
{
	if (ft_reverse_rotate(&stacks[s_a]))
		write(1, "rra\n", 4);
}

void	ft_reverse_rotate_b(t_stack *stacks)
{
	if (ft_reverse_rotate(&stacks[s_b]))
		write(1, "rrb\n", 4);
}

void	ft_reverse_rotate_2(t_stack *stacks)
{
	if (ft_reverse_rotate(&stacks[s_a]) || ft_reverse_rotate(&stacks[s_b]))
		write(1, "rrr\n", 4);
}
