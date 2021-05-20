/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:37:16 by msessa            #+#    #+#             */
/*   Updated: 2021/05/20 13:01:24 by msessa           ###   ########.fr       */
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

	result->nb_moves = malloc(sizeof(long long) * nb_progs);
	result->ratio = malloc(sizeof(float) * nb_progs);
	result->tot_wins = malloc(sizeof(int) * nb_progs);
	result->checker = malloc(sizeof(t_check) * nb_progs);
	result->is_winner = malloc(sizeof(bool) * nb_progs);
	i = 0;
	while (i < nb_progs)
	{
		result->nb_moves[i] = 0;
		result->ratio[i] = 0;
		result->tot_wins[i] = 0;
		i++;
	}
}

char	*ft_save_output(char *command)
{
	char		*output;
	char		buf[BUF_SIZE];
	size_t		read_result;
	long long	output_size;
	FILE		*process;

	output_size = 0;

	process = popen(command, "r");
	read_result = fread(buf, 1, BUF_SIZE, process);
	if (read_result > 0)
		output_size += read_result;
	while (read_result > 0)
	{
		read_result = fread(buf, 1, BUF_SIZE, process);
		if (read_result > 0)
			output_size += read_result;
	}
	pclose(process);
	output = malloc(sizeof(char) * (output_size + 1));
	output[output_size] = '\0';

	if (output_size > 0)
	{
		process = popen(command, "r");
		fread(output, 1, output_size, process);
		pclose(process);
	}
	return (output);
}

int	ft_count_args(char *s)
{
	long long	nb_args;

	nb_args = 0;
	while (*s != '\0')
	{
		if (*s == ' ')
			nb_args++;
		s++;
	}
	if (nb_args != 0)
		nb_args++;
	return (nb_args);
}

long long	ft_count_moves(char *s)
{
	long long	nb_moves;

	nb_moves = 0;
	while (*s != '\0')
	{
		if (*s == '\n')
			nb_moves++;
		s++;
	}
	return (nb_moves);
}

void	ft_print_line(t_result *result, int nb_progs)
{
	int	i;

	i = 0;
	while (i < nb_progs)
	{
		printf("x%-5.1f %*lld|",
			result->ratio[i],
			CELL_SIZE - 7,
			result->nb_moves[i]);
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
	char	full_test[4096];
	char	full_prog[4096];
	char	command[4000096];
	char	*output;

	i = 0;
	printf("    %*s|", CELL_SIZE, "Test name");
	j = 0;
	while (j < nb_progs)
	{
		printf("%*s|", CELL_SIZE, prog_files[j]);
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
		result->nb_args = ft_count_args(line);
		printf("    %-*s|", CELL_SIZE, test_files[i]);
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
			output = ft_save_output(command);
			result->nb_moves[j] = ft_count_moves(output);
			result->ratio[j] = (float)result->nb_moves[j] / result->nb_args;
			free(output);
			j++;
		}
		free(line);
		ft_print_line(result, nb_progs);
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
	free(result.ratio);
	free(result.tot_wins);
	free(result.is_winner);
	free(result.checker);
	ft_free_split(test_files);
	ft_free_split(prog_files);
	return (0);
}