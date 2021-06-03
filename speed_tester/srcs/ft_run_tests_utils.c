/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_tests_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:37:16 by msessa            #+#    #+#             */
/*   Updated: 2021/06/01 23:43:44 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"

int	ft_count_args(char *s)
{
	long long	nb_args;
	bool		is_separator;

	nb_args = 0;
	is_separator = false;
	while (*s != '\0')
	{
		if (*s != ' ')
			is_separator = true;
		else if (is_separator)
		{
			is_separator = false;
			nb_args++;
		}
		s++;
	}
	if (is_separator)
		nb_args++;
	return (nb_args);
}

long long	ft_count_moves(char *s)
{
	long long	nb_moves;

	if (!strcmp(s, "Error\n"))
		return (-1);
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
	int	timeout;

	i = 0;
	timeout = atoi(TIMEOUT);
	while (i < nb_progs)
	{
		if (result->prog_time[i] >= timeout)
			printf("%s%*s", CLR_RED, CELL_SIZE - 4, "TIMEOUT");
		else
		{
			if (result->checker[i] == check_ko
				|| (result->checker[i] == check_error
					&& result->nb_moves[i] != -1))
				printf(CLR_RED);
			else if (result->checker[i] == check_ok && result->pos[i] == 1)
				printf(CLR_GREEN);
			if (result->nb_moves[i] == -1)
				printf("%*s ", CELL_SIZE - 9, "ERROR");
			else
				printf(" x%-4.1f %*lld ",
					result->ratio[i],
					CELL_SIZE - 16,
					result->nb_moves[i]);
			if (result->checker[i] == check_ok)
				printf("[OK]");
			else if (result->checker[i] == check_ko)
				printf("[KO]");
			else if(result->checker[i] == check_error)
			{
				printf(CLR_YELLOW);
				printf("[ER]");
			}
			else if(result->checker[i] == check_void)
			{
				printf(CLR_YELLOW);
				printf("[__]");
			}
		}
		printf(CLR_GRAY);
		printf("%3ds", result->prog_time[i]);
		printf(CLR_WHITE);
		printf("|");
		i++;
	}
}