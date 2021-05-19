/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:28:01 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 11:13:21 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define BUFFER_SIZE 64
# include <unistd.h>
# include <stdlib.h>
# include "../../libft/libft.h"

int		get_next_line(int fd, char **line);
size_t	ft_partial_len(char *buf);
int		ft_free_exit(int fd, char *buf[1025], char **line);

#endif
