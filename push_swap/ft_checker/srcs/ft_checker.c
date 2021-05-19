/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:36:23 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 22:49:25 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_checker.h"

static t_op_type	ft_get_op(char *s)
{
	if (!ft_strncmp(s, "sa", 3))
		return (op_sa);
	else if (!ft_strncmp(s, "sb", 3))
		return (op_sb);
	else if (!ft_strncmp(s, "ss", 3))
		return (op_ss);
	else if (!ft_strncmp(s, "pa", 3))
		return (op_pa);
	else if (!ft_strncmp(s, "pb", 3))
		return (op_pb);
	else if (!ft_strncmp(s, "ra", 3))
		return (op_ra);
	else if (!ft_strncmp(s, "rb", 3))
		return (op_rb);
	else if (!ft_strncmp(s, "rr", 3))
		return (op_rr);
	else if (!ft_strncmp(s, "rra", 3))
		return (op_rra);
	else if (!ft_strncmp(s, "rrb", 3))
		return (op_rrb);
	else if (!ft_strncmp(s, "rrr", 3))
		return (op_rrr);
	else
		return (op_error);
}

static void	ft_do_op(t_data *data, t_op_type op)
{
	if (op == op_sa)
		ft_swap_a(data);
	else if (op == op_sb)
		ft_swap_b(data);
	else if (op == op_ss)
		ft_swap_2(data);
	else if (op == op_pa)
		ft_push_a(data);
	else if (op == op_pb)
		ft_push_b(data);
	else if (op == op_ra)
		ft_rotate_a(data);
	else if (op == op_rb)
		ft_rotate_b(data);
	else if (op == op_rr)
		ft_rotate_2(data);
	else if (op == op_rra)
		ft_reverse_rotate_a(data);
	else if (op == op_rrb)
		ft_reverse_rotate_b(data);
	else if (op == op_rrr)
		ft_reverse_rotate_2(data);
}

static void	ft_check_sort(t_data *data)
{
	int	i;
	
	i = 1;

	while (i < data->s_a.size)
	{
		if (data->s_a.stack[i].nb > data->s_a.stack[i -1].nb)
			break ;
		i++;
	}
	if (data->s_b.size != 0 || i < data->s_a.size)
		write(STDOUT_FILENO, "KO\n", 3);
	else
		write(STDOUT_FILENO, "OK\n", 3);
}

void	ft_checker(t_data *data)
{
	char		*line;
	int			read_result;
	t_op_type	op;

	line = 0;
	op = op_none;
	read_result = get_next_line(STDIN_FILENO, &line) > 0;
	while (read_result > 0)
	{
		op = ft_get_op(line);
		free(line);
		line = 0;
		if (op == op_error)
			break ;
		ft_do_op(data, op);
		read_result = get_next_line(STDIN_FILENO, &line) > 0;
	}
	if (op == op_error || read_result < 0)
		write(STDERR_FILENO, "Error\n", 6);
	else
		ft_check_sort(data);
}
