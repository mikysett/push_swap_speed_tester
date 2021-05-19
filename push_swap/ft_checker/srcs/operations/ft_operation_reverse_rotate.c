/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operation_reverse_rotate.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:02:41 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 10:42:04 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static bool	ft_reverse_rotate(t_stack *s)
{
	int		i;
	int		top;
	t_nb	buf;

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

void	ft_reverse_rotate_a(t_data *data)
{
	ft_reverse_rotate(&data->s_a);
}

void	ft_reverse_rotate_b(t_data *data)
{
	ft_reverse_rotate(&data->s_b);
}

void	ft_reverse_rotate_2(t_data *data)
{
	ft_reverse_rotate(&data->s_a);
	ft_reverse_rotate(&data->s_b);
}
