/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:38:11 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 17:40:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Only for tests in dev, not to be submitted

#include "../headers/ft_push_swap.h"

void	ft_print_stack(t_stack *s)
{
	int	i;

	i = 0;
	while (i < s->size)
	{
		printf("%3i. %012i\n", i, s->stack[i]);
		i++;
	}
}