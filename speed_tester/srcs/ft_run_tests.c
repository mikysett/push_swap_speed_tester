/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:44:31 by msessa            #+#    #+#             */
/*   Updated: 2021/05/21 17:59:34 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"

static void	ft_print_header(char **prog_files, int nb_progs)
{
	int	i;

	i = 0;
	printf("    %*s|", CELL_SIZE, "Test name");
	while (i < nb_progs)
	{
		printf("%*.*s|", CELL_SIZE, CELL_SIZE, prog_files[i]);
		i++;
	}
	printf("\n");
}

static void	ft_print_totals(t_result *result, int nb_tests, int nb_progs)
{
	int	i;

	i = 0;
	printf("    %*s|", CELL_SIZE, "TOTALS");
	while (i < nb_progs)
	{
		printf("%*d / %3d|", CELL_SIZE - 6, result->tot_wins[i], nb_tests);
		i++;
	}
	printf("\n");
}

static void	ft_get_test_input(char *file_name, char **out)
{
	int			fd;
	static char	full_test[1028];

	full_test[0] = '\0';
	strcat(full_test, "tests/");
	strcat(full_test, file_name);
	fd = open(full_test, O_RDONLY);
	get_next_line(fd, out);
	close(fd);
}


static char	*ft_save_ps_output(char *command)
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

t_check	ft_do_check(char *input, char *ps_output)
{
	FILE		*process;
	FILE		*checker_buffer;
	static char	command[4000096];
	char		checker_res[11];
	int			read_res;

	checker_buffer = fopen("checker_buffer", "w");
	if (strcmp(ps_output, "Error\n") != 0)
		fwrite(ps_output, 1, strlen(ps_output), checker_buffer);
	fclose(checker_buffer);
	command[0] = '\0';
	strcat(command, "./../push_swap/checker 2>&1 ");
	strcat(command, input);
	if (*input != '\0')
		strcat(command, " < checker_buffer");
	process = popen(command, "r");
	read_res = fread(checker_res, 1, 10, process);
	pclose(process);
	remove("checker_buffer");
	if (read_res >= 0)
		checker_res[read_res] = '\0';
	else
		checker_res[0] = '\0';
	if (!strcmp(checker_res, "OK\n"))
		return (check_ok);
	else if (!strcmp(checker_res, "KO\n"))
		return (check_ko);
	else if(!strcmp(checker_res, "Error\n"))
		return (check_error);
	else // if(!strcmp(checker_res, ""))
		return (check_void);
}

void	ft_set_wins(t_result *result, int nb_progs)
{
	int			i;
	long long	best_score;

	best_score = -2;
	i = 0;
	while (i < nb_progs)
	{
		if (best_score == -2
			|| (result->checker[i] == check_ok
			&& result->nb_moves[i] < best_score))
			best_score = result->nb_moves[i];
		i++;
	}
	i = 0;
	while (i < nb_progs)
	{
		// if (result->checker[i] == check_error
		// 	&& result->nb_moves[i] == -1)
		// {
		// 	result->is_winner[i] = true;
		// 	result->tot_wins[i]++;
		// }
		if (result->checker[i] == check_ok
			&& result->nb_moves[i] == best_score)
		{
			result->is_winner[i] = true;
			result->tot_wins[i]++;
		}
		else
			result->is_winner[i] = false;
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
	char	*test_input;
	char	full_prog[1028];
	char	command[4000096];
	char	*ps_output;

	i = 0;
	ft_print_header(prog_files, nb_progs);
	while (i < nb_tests)
	{
		ft_get_test_input(test_files[i], &test_input);
		result->nb_args = ft_count_args(test_input);
		printf("    %-*.*s|", CELL_SIZE, CELL_SIZE, test_files[i]);
		j = 0;
		while (j < nb_progs)
		{
			full_prog[0] = '\0';
			strcat(full_prog, "prog_to_test/");
			strcat(full_prog, prog_files[j]);
			command[0] = '\0';
			strcat(command, "./");
			strcat(command, full_prog);
			strcat(command, " 2>&1 ");
			strcat(command, test_input);
			ps_output = ft_save_ps_output(command);
			result->nb_moves[j] = ft_count_moves(ps_output);
			if (result->nb_moves[j] > 0)
				result->ratio[j] = (float)result->nb_moves[j] / result->nb_args;
			else
				result->ratio[j] = 0;
			result->checker[j] = ft_do_check(test_input, ps_output);
			free(ps_output);
			j++;
		}
		free(test_input);
		ft_set_wins(result, nb_progs);
		ft_print_line(result, nb_progs);
		printf("\n");
		i++;
	}
	ft_print_totals(result, nb_tests, nb_progs);
}