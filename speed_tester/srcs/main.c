/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:37:16 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 23:18:50 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"

void	ft_free_split(char **args)
{
	int i;

	if (args)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}

int	ft_count_split(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

char	**ft_files_in_dir(char *path)
{
	DIR				*src_dir;
	struct dirent	*file_name;
	char			src_files[4096];

	src_files[0] = '\0';
		src_dir = opendir(path);
		if (src_dir)
		{
			while ((file_name = readdir(src_dir)))
			{
				if (!strcmp (file_name->d_name, ".")
					|| !strcmp (file_name->d_name, ".."))
					continue;
				strcat(src_files, file_name->d_name);
				strcat(src_files, "#");
			}
		}
		closedir(src_dir);
	return (ft_split(src_files, '#'));
}

void	ft_init_result(int nb_progs, t_result *result)
{
	int	i;

	result->nb_moves = malloc(sizeof(int) * nb_progs);
	result->tot_wins = malloc(sizeof(int) * nb_progs);
	i = 0;
	while (i < nb_progs)
	{
		result->nb_moves[i] = 0;
		result->tot_wins[i] = 0;
		i++;
	}
}

void	ft_run_tests(t_result *result,
		char **test_files,
		char **prog_files,
		int nb_tests,
		int nb_progs)
{
	int		i;
	int		j;
	char	*line;
	int		fd;
	pid_t	pid;
	char	full_test[4096];
	char	full_prog[4096];
	char	command[4000096];
	FILE	*process;

	i = 0;
	printf("    %20s|", "Test name");
	j = 0;
	while (j < nb_progs)
	{
		printf("%20s|", prog_files[j]);
		j++;
	}
	printf("\n");
	while (i < nb_tests)
	{
		full_test[0] = 0;
		strcat(full_test, "tests/");
		strcat(full_test, test_files[i]);
		fd = open(full_test, O_RDONLY);
		get_next_line(fd, &line);
		close(fd);
		printf("    %-20s|", test_files[i]);
		j = 0;
		while (j < nb_progs)
		{
			full_prog[0] = 0;
			strcat(full_prog, "prog_to_test/");
			strcat(full_prog, prog_files[j]);
			command[0] = 0;
			strcat(command, "./");
			strcat(command, full_prog);
			strcat(command, " ");
			strcat(command, line);
			// printf("command: %s", command);
			// pid = fork();
			// if (pid == 0)
			// 	execlp(full_prog, "push_swap", line, NULL);
			// wait(NULL);
			process = popen(command, "r");

			pclose(process);
			j++;
		}
		free(line);
		printf("\n");
		i++;
	}
}

void	ft_sort_tests(char **test_files, int nb_tests)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	while (i < nb_tests)
	{
		j = i + 1;
		while (j < nb_tests)
		{
			if (strcmp(test_files[i], test_files[j]) < 0)
			{
				buf = test_files[i];
				test_files[i] = test_files[j];
				test_files[j] = buf;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < nb_tests)
	{
		printf("%s\n", test_files[i]);
		i++;
	}
}

int	main(void)
{
	char		**test_files;
	char		**prog_files;
	int			nb_tests;
	int			nb_progs;
	t_result	result;

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
	ft_sort_tests(test_files, nb_tests);
	ft_init_result(nb_progs, &result);
	ft_run_tests(&result, test_files, prog_files, nb_tests, nb_progs);
	free(result.nb_moves);
	free(result.tot_wins);
	ft_free_split(test_files);
	ft_free_split(prog_files);
	return (0);
}