/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:59:05 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 22:29:03 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_set_pos(t_stack *s, bool is_initial)
{
	int		i;

	i = 0;
	if (is_initial)
		while (i < s->size)
		{
			s->stack[i].initial_pos = i;
			i++;
		}
	else
		while (i < s->size)
		{
			s->stack[i].sort_pos = i;
			i++;
		}
}

static int	ft_partition(t_stack *s, int low, int high, int pivot)
{
	t_nb	buf;
	int		i;
	int		curr_pos;

	i = high;
	// printf("-> ");
	while (i >= low && s->stack[i].nb < pivot)
		i--;
	curr_pos = i;
	// printf("pivot: %10d, low: %5d, high: %5d, curr_pos: %5d, ",
	// 	pivot, low, high, curr_pos);
	while (i >= low)
	{
		if (s->stack[i].nb < pivot)
		{
			if (i != curr_pos)
			{
				buf = s->stack[i];
				s->stack[i] = s->stack[curr_pos];
				s->stack[curr_pos] = buf;
			}
			curr_pos--;
		}
		i--;
	}
	if (curr_pos == high)
	{
		// printf("returned pos (-1): %d\n", curr_pos - 1);
		return (curr_pos - 1);
	}
	// printf("returned pos: %d\n", curr_pos);
	return (curr_pos);
}

void	ft_set_sort_pos(t_stack *s, int low, int high)
{
	int	new_division;
	int	pivot;

	if (low >= high)
		return ;
	pivot = s->stack[high].nb;
	// if (pivot == 164011056)
	// 	return ;
	new_division = ft_partition(s, low, high, pivot);
	ft_set_sort_pos(s, low, new_division);
	ft_set_sort_pos(s, new_division + 1, high);
}

void	ft_fix_pos(t_stack *s)
{
	int		i;
	int		initial_pos;
	t_nb	buf;

	i = 0;
	ft_set_pos(s, false);
	while (i < s->size)
	{
		if (s->stack[i].initial_pos != i)
		{
			initial_pos = s->stack[i].initial_pos;
			buf = s->stack[initial_pos];
			s->stack[initial_pos] = s->stack[i];
			s->stack[i] = buf;
		}
		else
			i++;
	}
}

bool	ft_sort(t_data *data)
{
	printf("SORTING STARTS\n");
	ft_set_pos(&data->s_a, true);
	printf("QUICKSORT STARTS\n");
	ft_set_sort_pos(&data->s_a, 0, data->s_a.size - 1);
	if (ft_duplicated_nb(&data->s_a))
		return (false);
	// To test
	ft_is_sorted(&data->s_a);
	ft_fix_pos(&data->s_a);
	// To test
	// ft_print_stack(&data->s_a);
	return (true);
}
