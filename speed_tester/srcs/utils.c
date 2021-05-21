/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:36:16 by msessa            #+#    #+#             */
/*   Updated: 2021/05/21 13:18:55 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"

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
		result->is_winner[i] = false;
		i++;
	}
}

void	ft_free_all(t_result *result, char **test_files, char **prog_files)
{
	free(result->nb_moves);
	free(result->ratio);
	free(result->tot_wins);
	free(result->is_winner);
	free(result->checker);
	ft_free_split(test_files);
	ft_free_split(prog_files);
}
