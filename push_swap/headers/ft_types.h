/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:54:02 by msessa            #+#    #+#             */
/*   Updated: 2021/05/18 16:59:13 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

# define CLR_WHITE	"\033[0;37m"
# define CLR_BLACK	"\033[0;30m"
# define CLR_RED	"\033[0;31m"
# define CLR_GREEN	"\033[0;32m"

typedef enum	s_op_type
{
	op_sa,
	op_sb,
	op_ss,
	op_pa,
	op_pb,
	op_ra,
	op_rb,
	op_rr,
	op_rra,
	op_rrb,
	op_rrr,
	op_none,
	op_error
}				t_op_type;

typedef struct	s_nb
{
	int		nb;
	bool	is_sorted;
	int		sort_pos;
	int		initial_pos;
}				t_nb;

typedef struct	s_stack
{
	t_nb	*stack;
	int		size;
}				t_stack;

typedef struct	s_data
{
	t_list	**ops;
	t_stack	s_a;
	t_stack	s_b;
}				t_data;

#endif
