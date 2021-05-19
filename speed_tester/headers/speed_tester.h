/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speed_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 19:38:14 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 21:18:56 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPEED_TESTER_H
# define SPEED_TESTER_H

# define CLR_WHITE	"\033[0;37m"
# define CLR_BLACK	"\033[0;30m"
# define CLR_RED	"\033[0;31m"
# define CLR_GREEN	"\033[0;32m"


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

# include "libft.h"
# include "gnl.h"

typedef struct	s_test
{
	char	*name;
	char	*body;
}				t_test;

typedef struct	s_result
{
	int		*nb_moves;
	int		*tot_wins;
	bool	*is_sorted;
}				t_result;


#endif