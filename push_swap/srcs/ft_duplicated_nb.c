/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicated_nb.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 17:38:11 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 16:48:48 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

bool	ft_duplicated_nb(t_stack *s)
{
	int	i;
	
	i = 1;
	while (i < s->size)
	{
		if (s->stack[i].nb == s->stack[i - 1].nb)
			return (true);
		i++;
	}
	return (false);
}