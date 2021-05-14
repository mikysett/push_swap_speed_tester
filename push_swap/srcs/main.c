/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:43:40 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 17:26:57 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stacks[2];

	if (argc == 1)
		return (0);
	if (!ft_parser(argc, argv))
		write(STDERR_FILENO, "Error\n", 6);
	else if (ft_init_stacks(argc, argv, stacks))
	{
		if (ft_duplicated_nb(&stacks[s_a]))
			write(STDERR_FILENO, "Error\n", 6);
		else
			ft_sort(stacks);
		ft_free_stacks(stacks);
	}
	else
		write(STDERR_FILENO, "Error\n", 6);
	return (0);
}
