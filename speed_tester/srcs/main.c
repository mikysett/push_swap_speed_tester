/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <mikysett@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:37:16 by msessa            #+#    #+#             */
/*   Updated: 2021/06/30 19:33:50 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"

static char	*ft_create_path(char *path);

int	main(int argc, char **argv)
{
	char		**test_files;
	char		**prog_files;
	int			nb_tests;
	int			nb_progs;
	t_result	result;

	// To fix color changes giving different shades of white
	printf(CLR_WHITE);
	if (argc > 1)
		result.tests_path = ft_create_path(argv[1]);
	else
		result.tests_path = ft_strdup("tests/");
	if (argc > 2)
		result.progs_path = ft_create_path(argv[2]);
	else
		result.progs_path = ft_strdup("prog_to_test/");
	test_files = ft_files_in_dir(result.tests_path);
	prog_files = ft_files_in_dir(result.progs_path);
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

static char	*ft_create_path(char *path)
{
	char	*new_path;
	int		path_size;

	path_size = ft_strlen(path);
	if (path[path_size - 1] == '/')
		return (ft_strdup(path));
	new_path = malloc(sizeof(char) * path_size + 2);
	if (!new_path)
	{
		printf("can't allocate memory with malloc()!!\n");
		exit(EXIT_FAILURE);
	}
	new_path[0] = '\0';
	ft_strlcat(new_path, path, path_size + 2);
	ft_strlcat(new_path, "/", path_size + 2);
	printf("directory: %s\n", new_path);
	return (new_path);
}