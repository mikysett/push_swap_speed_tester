/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 15:54:02 by msessa            #+#    #+#             */
/*   Updated: 2021/05/14 17:41:36 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef enum	e_stack_name
{
	s_a = 0,
	s_b = 1
}				t_stack_name;

typedef struct	s_stack
{
	int	*stack;
	int	size;
}				t_stack;


#endif