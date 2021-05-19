/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 16:33:19 by msessa            #+#    #+#             */
/*   Updated: 2021/05/18 13:02:45 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

bool	ft_init_data(int argc, char **argv, t_data *data)
{
	int	i;
	int	j;

	j = 1;
	i = argc - 1;
	data->s_a.size = i;
	data->s_b.size = 0;
	data->ops = malloc(sizeof(t_list *));
	data->s_a.stack = malloc(sizeof(t_nb) * i);
	data->s_b.stack = malloc(sizeof(t_nb) * i);
	if (!data->ops || !data->s_a.stack || !data->s_b.stack)
		return (false);
	*data->ops = 0;
	while (--i >= 0)
	{
		data->s_a.stack[i].nb = ft_atoi(argv[j]);
		data->s_a.stack[i].initial_pos = i;
		j++;
	}
	return (true);
}
