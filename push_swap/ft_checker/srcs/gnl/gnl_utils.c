/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:28:06 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 11:16:43 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

int	ft_free_exit(int fd, char *buf[1025], char **line)
{
	free(buf[fd]);
	free(*line);
	buf[fd] = 0;
	*line = 0;
	return (-1);
}

size_t	ft_partial_len(char *buf)
{
	char	*o_buf;

	o_buf = buf;
	while (*buf && *buf != '\n')
		buf++;
	return (buf - o_buf);
}
