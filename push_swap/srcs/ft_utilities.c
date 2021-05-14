/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:41:20 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 16:42:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

void	ft_free_stacks(t_stack *stacks)
{
	if (stacks[s_a].stack)
		free(stacks[s_a].stack);
	if (stacks[s_b].stack)
		free(stacks[s_b].stack);
}