/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:37:16 by msessa            #+#    #+#             */
/*   Updated: 2021/05/21 14:22:38 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"


int	main(void)
{
	char		**test_files;
	char		**prog_files;
	int			nb_tests;
	int			nb_progs;
	t_result	result;

	// To fix color changes giving different shades of white
	printf(CLR_WHITE);
	test_files = ft_files_in_dir("tests/");
	prog_files = ft_files_in_dir("prog_to_test/");
	nb_tests = ft_count_split(test_files);
	nb_progs = ft_count_split(prog_files);

	if (!test_files)
	{
		printf("---> No tests found in test/\n");
		return (0);
	}
	if (!prog_files)
	{
		printf("---> No programs found in prog_to_test/\n");
		return (0);
	}
	ft_sort_files(test_files, nb_tests);
	ft_sort_files(prog_files, nb_progs);
	ft_init_result(nb_progs, &result);
	ft_run_tests(&result, test_files, prog_files, nb_tests, nb_progs);
	ft_free_all(&result, test_files, prog_files);
	return (0);
}