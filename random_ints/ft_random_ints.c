/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random_ints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 17:06:24 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 18:24:46 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <time.h>

// Small utility to generate a randomized int array
// To compile separately

bool	ft_duplicated_nb(int nb, char *pos_hash, char *neg_hash)
{
	if (nb >= 0)
	{
		if (pos_hash[nb])
			return (true);
		pos_hash[nb] = 1;
	}
	else
	{
		if (neg_hash[nb + INT_MAX + 1])
			return (true);
		neg_hash[nb + INT_MAX + 1] = 1;
	}
	return (false);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb_numbers;
	int		min;
	int		max;
	long	range;
	int		random_nb;
	char	*pos_hash;
	char	*neg_hash;
	time_t	curr_time;

	pos_hash = calloc((size_t)INT_MAX + 1, sizeof(char));
	neg_hash = calloc((size_t)INT_MAX + 1, sizeof(char));
	if (!pos_hash || !neg_hash)
	{
		printf("Error\n");
		return (0);
	}
	if (argc == 1)
	{
		printf("-->Random numbers generator\n");
		printf("To use the program run it as follow:\n");
		printf("./random_ints NUMBERS [MIN] [MAX]\n");
		return (0);
	}
	nb_numbers = atoi(argv[1]);
	if (argc > 2)
		min = atoi(argv[2]);
	else
		min = INT_MIN;
	if (argc > 3)
		max = atoi(argv[3]);
	else
		max = INT_MAX;
	if (min >= 0 || max < 0)
		range = labs(max - min) + (long)1;
	else
		range = max + labs(min) + (long)1;
	if (nb_numbers < 0 || min > max || nb_numbers > range)
	{
		printf("Error\n");
		return (0);
	}
	srand(time(NULL));
	if (max - min + 1 != 0)
		random_nb = (rand() % (max - min + 1)) + min;
	else
		random_nb = rand() + min;
	ft_duplicated_nb(random_nb, pos_hash, neg_hash);
	printf("%d", random_nb);
	i = 1;
	while (i < nb_numbers)
	{
		srand(time(NULL) + i);
		if (max - min + 1 != 0)
			random_nb = (rand() % (max - min + 1)) + min;
		else if (i % 2 == 0)
			random_nb = rand() + min;
		else
			random_nb = rand();
		if (!ft_duplicated_nb(random_nb, pos_hash, neg_hash))
			printf(" %d", random_nb);
		else
			continue ;
		i++;
	}
	return (0);
}