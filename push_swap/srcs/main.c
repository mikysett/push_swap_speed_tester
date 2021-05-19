/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:43:40 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 16:46:15 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 1)
		return (0);
	printf("Parsing starts\n");
	if (!ft_parser(argc, argv))
		write(STDERR_FILENO, "Error\n", 6);
	else if (ft_init_data(argc, argv, &data))
	{
		printf("Parsing completed\n");
		if (!ft_sort(&data))
			write(STDERR_FILENO, "Error\n", 6);
		ft_free_data(&data);
	}
	else
		write(STDERR_FILENO, "Error\n", 6);
	return (0);
}
