/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:38:14 by msessa            #+#    #+#             */
/*   Updated: 2021/05/24 17:33:28 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPEED_TESTER_H
# define SPEED_TESTER_H

# define CLR_WHITE	"\033[0;37m"
# define CLR_BLACK	"\033[0;30m"
# define CLR_GRAY	"\033[30;1m"
# define CLR_RED	"\033[0;31m"
# define CLR_GREEN	"\033[0;32m"
# define CLR_YELLOW	"\033[0;33m"

# define CELL_SIZE		24
# define BUF_SIZE		10000000
# define OP_STR_SIZE	4000000
# define TIMEOUT		"5"

# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <libgen.h>
# include <ctype.h>
# include <string.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>

# include "libft.h"
# include "gnl.h"

typedef struct	s_test
{
	char	*name;
	char	*body;
}				t_test;

typedef enum	e_check
{
	check_ok,
	check_ko,
	check_error,
	check_void
}				t_check;

typedef struct	s_result
{
	int			nb_args;
	long long	*nb_moves;
	float		*ratio;
	int			*tot_wins;
	int			*pos;
	int			*pos_sum;
	int			*tot_tests;
	int			*prog_time;
	int			*tot_time;
	t_check		*checker;
}				t_result;

void		ft_free_split(char **args);
int			ft_count_split(char **args);
void		ft_init_result(int nb_progs, t_result *result);

char		**ft_files_in_dir(char *path);
void		ft_sort_files(char **test_files, int nb_tests);

void		ft_init_result(int nb_progs, t_result *result);
void		ft_free_all(t_result *result, char **test_files, char **prog_files);

void	ft_run_tests(t_result *result,
		char **test_files,
		char **prog_files,
		int nb_tests,
		int nb_progs);

int			ft_count_args(char *s);
long long	ft_count_moves(char *s);
void		ft_print_line(t_result *result, int nb_progs);


#endif