/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:44:31 by msessa            #+#    #+#             */
/*   Updated: 2021/05/24 11:49:22 by msessa           ###   ########.fr       */
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
	printf("    %*s|", CELL_SIZE, "TOTAL WINS");
	while (i < nb_progs)
	{
		printf("%*d/%3d|", CELL_SIZE - 4, result->tot_wins[i], nb_tests);
		i++;
	}
	printf("\n");
	i = 0;
	printf("    %*s|", CELL_SIZE, "AVG POSITION");
	while (i < nb_progs)
	{
		printf("%*s%-*.1f%s%3ds%s|",
			(CELL_SIZE - 4) / 2, "",
			(CELL_SIZE - 4) / 2,
			(float)result->pos_sum[i] / result->tot_tests[i],
			CLR_GRAY,
			result->tot_time[i],
			CLR_WHITE);
		i++;
	}
	printf("\n");
}

static void	ft_get_test_input(char *file_name, char **out)
{
	int			fd;
	static char	full_test[1028];
	size_t		out_size;

	full_test[0] = '\0';
	strcat(full_test, "tests/");
	strcat(full_test, file_name);
	fd = open(full_test, O_RDONLY);
	get_next_line(fd, out);
	close(fd);
	out_size = strlen(*out);
	if (out_size >= BUF_SIZE)
	{
		printf(CLR_RED);
		printf("\n!The size of the test (%lu) exceeds the buffer size!\n", out_size);
		printf("-> Increment BUF_SIZE accordingly in headers/speed_tester.h\n");
		printf(CLR_WHITE);
	}
}

static void	ft_save_ps_output(char *command, char *output, int *prog_time, int *tot_time)
{
	size_t		read_result;
	long long	output_size;
	FILE		*process;
	time_t		time_start;
	time_t		time_end;

	time_start = time(NULL);
	process = popen(command, "r");
	read_result = fread(output, 1, OP_STR_SIZE, process);
	if (read_result > 0)
		output_size = read_result;
	else
		output_size = 0;
	pclose(process);
	time_end = time(NULL);
	*prog_time = time_end - time_start;
	*tot_time += *prog_time;
	output[output_size] = '\0';
	if (output_size == OP_STR_SIZE)
	{
		printf(CLR_RED);
		printf("\n!The size of the push_swap output exceeds the buffer size!\n");
		printf("-> Increment OP_STR_SIZE accordingly in headers/speed_tester.h\n");
		printf(CLR_WHITE);
	}
}

t_check	ft_do_check(char *input, char *ps_output, char *command)
{
	FILE		*process;
	FILE		*checker_buffer;
	char		checker_res[11];
	int			read_res;

	checker_buffer = fopen("checker_buffer", "w");
	if (strcmp(ps_output, "Error\n") != 0)
		fwrite(ps_output, 1, strlen(ps_output), checker_buffer);
	fclose(checker_buffer);
	command[0] = '\0';
	strcat(command, "./checker 2>&1 ");
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

void	ft_set_pos(t_result *result, int nb_progs)
{
	int			i;
	int			j;
	long long	score_sel;
	
	i = -1;
	while (++i < nb_progs)
	{
		if (result->checker[i] != check_ok)
			continue;
		result->pos[i] = 1;
		score_sel = result->nb_moves[i];
		j = -1;
		while(++j < nb_progs)
		{
			if (j == i || result->checker[j] != check_ok)
				continue;
			if (score_sel > result->nb_moves[j])
				result->pos[i]++;
		}
		if (result->pos[i] == 1)
			result->tot_wins[i]++;
		result->tot_tests[i]++;
		result->pos_sum[i] += result->pos[i];
	}
}

void	ft_run_tests(t_result *result,
		char **test_files,
		char **prog_files,
		int nb_tests,
		int nb_progs)
{
	int			i;
	int			j;
	char		*test_input;
	char		full_prog[1028];
	static char	command[BUF_SIZE + 500];
	char		*ps_output;

	i = 0;
	ps_output = malloc(sizeof(char) * (OP_STR_SIZE + 1));
	if (!ps_output)
	{
		printf("Failed to allocate memory for ps_output, quiting");
		exit(EXIT_FAILURE);
	}
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
			ft_save_ps_output(command,
				ps_output,
				&result->prog_time[j],
				&result->tot_time[j]);
			result->nb_moves[j] = ft_count_moves(ps_output);
			if (result->nb_moves[j] > 0)
				result->ratio[j] = (float)result->nb_moves[j] / result->nb_args;
			else
				result->ratio[j] = 0;
			result->checker[j] = ft_do_check(test_input, ps_output, command);
			j++;
		}
		free(test_input);
		ft_set_pos(result, nb_progs);
		ft_print_line(result, nb_progs);
		printf("\n");
		i++;
	}
	free(ps_output);
	ft_print_totals(result, nb_tests, nb_progs);
}