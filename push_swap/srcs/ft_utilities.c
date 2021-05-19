/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:41:20 by msessa            #+#    #+#             */
/*   Updated: 2021/05/18 13:00:32 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ft_delete_op(void *void_op)
{
	t_op_type	*op;
	
	op = (t_op_type *)void_op;
	if (op)
		free(op);
}

void	ft_free_data(t_data *data)
{
	if (data->s_a.stack)
		free(data->s_a.stack);
	if (data->s_b.stack)
		free(data->s_b.stack);
	if (data->ops)
	{
		ft_lstclear(data->ops, ft_delete_op);
		free(data->ops);
	}
}