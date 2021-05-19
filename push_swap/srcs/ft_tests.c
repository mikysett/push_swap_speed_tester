/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:38:11 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 19:18:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Only for tests in dev, not to be submitted

#include "ft_push_swap.h"

void	ft_is_sorted(t_stack *s)
{
	bool	sorted;
	int		i;
	
	sorted = true;
	i = 1;
	while (i < s->size)
	{

		if (s->stack[i].nb > s->stack[i - 1].nb)
		{
			printf("%s%4i. %20i|%20i|%20i|%s\n", CLR_RED,
			i,
			s->stack[i].nb,
			s->stack[i].initial_pos,
			s->stack[i].sort_pos,
			CLR_WHITE);
			sorted = false;
		}
		else
		{
			printf("%4i. %20i|%20i|%20i|\n",
			i,
			s->stack[i].nb,
			s->stack[i].initial_pos,
			s->stack[i].sort_pos);
		}
		i++;
	}
	if (sorted)
		printf("%sARRAY SORTED%s\n", CLR_GREEN, CLR_WHITE);
	else
		printf("%sARRAY NOT SORTED%s\n", CLR_RED, CLR_WHITE);
}

void	ft_print_stack(t_stack *s)
{
	int	i;

	i = 0;
	printf("----  %20s|%20s|%20s|\n", "NUMBER", "INITIAL POS", "SORTED POS");
	while (i < s->size)
	{
		printf("%4i. %20i|%20i|%20i|\n", i,
			s->stack[i].nb,
			s->stack[i].initial_pos,
			s->stack[i].sort_pos);
		i++;
	}
}