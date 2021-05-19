/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 22:25:06 by msessa            #+#    #+#             */
/*   Updated: 2021/05/19 10:43:22 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

static char	*ft_update_line(char *buf, char *line)
{
	size_t	buf_chunk;
	char	*bigger_line;
	size_t	line_len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	buf_chunk = ft_partial_len(buf);
	line_len = ft_strlen(line);
	bigger_line = malloc(sizeof(char) * (line_len + buf_chunk + 1));
	if (!bigger_line)
		return (0);
	while (i < line_len)
	{
		bigger_line[i] = line[i];
		i++;
	}
	free(line);
	while (j < buf_chunk)
		bigger_line[i + j++] = *buf++;
	bigger_line[i + j] = '\0';
	return (bigger_line);
}

static int	ft_update_buf(char *buf)
{
	size_t	buf_chunk;
	size_t	i;
	size_t	j;

	buf_chunk = ft_partial_len(buf);
	if (!buf[buf_chunk])
	{
		*buf = '\0';
		return (0);
	}
	i = buf_chunk + 1;
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	buf[j] = '\0';
	return (1);
}

static int	ft_init_vars(int fd, char *buf[1025], char **line)
{
	*line = malloc(sizeof(char) * 1);
	if (!*line)
		return (0);
	**line = '\0';
	if (!buf[fd])
	{
		buf[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf[fd])
			return (0);
		buf[fd][0] = '\0';
	}
	return (1);
}

static int	ft_update_outputs(int fd, char *buf[1025], char **line)
{
	if (*buf[fd] != '\0')
	{
		*line = ft_update_line(buf[fd], *line);
		if (!*line)
		{
			free(buf[fd]);
			buf[fd] = 0;
			return (-1);
		}
		if (ft_update_buf(buf[fd]))
			return (1);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buf[1025] = {0};
	int			read_out;
	int			update;

	if (!BUFFER_SIZE || !line || fd < 0 || fd > 1024
		|| !ft_init_vars(fd, buf, line))
		return (-1);
	while (1)
	{
		update = ft_update_outputs(fd, buf, line);
		if (update != 0)
			return (update);
		read_out = read(fd, buf[fd], BUFFER_SIZE);
		if (read_out < 0)
			return (ft_free_exit(fd, buf, line));
		else if (read_out == 0)
		{
			free(buf[fd]);
			buf[fd] = 0;
			return (0);
		}
		buf[fd][read_out] = '\0';
	}
}
