/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:42:57 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 18:37:02 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "ft_types.h"
# include "ft_sort.h"
# include "ft_operation_swap.h"
# include "ft_operation_push.h"
# include "ft_operation_rotate.h"
# include "ft_operation_reverse_rotate.h"

# include "ft_tests.h"

bool	ft_parser(int argc, char **argv);
bool	ft_init_stacks(int argc, char **argv, t_stack *stacks);
bool	ft_duplicated_nb(t_stack *stack_a);

void	ft_free_stacks(t_stack *stacks);

#endif
