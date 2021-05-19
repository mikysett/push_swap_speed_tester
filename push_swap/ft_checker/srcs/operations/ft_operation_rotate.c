/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:02:41 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 10:20:33 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static bool	ft_rotate(t_stack *s)
{
	int		top;
	t_nb	buf;

	if (s->size < 2)
		return (false);
	top = s->size - 1;
	buf = s->stack[top];
	while (top >= 0)
	{
		s->stack[top] = s->stack[top - 1];
		top--;
	}
	s->stack[0] = buf;
	return (true);
}

void	ft_rotate_a(t_data *data)
{
	ft_rotate(&data->s_a);
}

void	ft_rotate_b(t_data *data)
{
	ft_rotate(&data->s_b);
}

void	ft_rotate_2(t_data *data)
{
	ft_rotate(&data->s_a);
	ft_rotate(&data->s_b);
}
