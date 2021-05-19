/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:03:00 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 22:24:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	if (!ft_parser(argc, argv))
		write(STDERR_FILENO, "Error\n", 6);
	else if (ft_init_data(argc, argv, &data))
	{
		ft_set_pos(&data.s_a, true);
		ft_set_sort_pos(&data.s_a, 0, data.s_a.size - 1);
		if (ft_duplicated_nb(&data.s_a))
			write(STDERR_FILENO, "Error\n", 6);
		else
		{
			ft_fix_pos(&data.s_a);
			ft_checker(&data);
		}
		ft_free_data(&data);
	}
	else
		write(STDERR_FILENO, "Error\n", 6);
	return (0);
}
