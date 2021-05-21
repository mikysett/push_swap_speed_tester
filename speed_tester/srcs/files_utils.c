/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:36:16 by msessa            #+#    #+#             */
/*   Updated: 2021/05/21 14:21:53 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "speed_tester.h"

char	**ft_files_in_dir(char *path)
{
	DIR				*src_dir;
	struct dirent	*file_name;
	char			src_files[4096];

	src_files[0] = '\0';
		src_dir = opendir(path);
		if (src_dir)
		{
			while ((file_name = readdir(src_dir)))
			{
				if (!strcmp (file_name->d_name, ".")
					|| !strcmp (file_name->d_name, ".."))
					continue;
				strcat(src_files, file_name->d_name);
				strcat(src_files, "#");
			}
		}
		closedir(src_dir);
	return (ft_split(src_files, '#'));
}

void	ft_sort_files(char **test_files, int nb_files)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	while (i < nb_files)
	{
		j = i + 1;
		while (j < nb_files)
		{
			if (strcmp(test_files[i], test_files[j]) < 0)
			{
				buf = test_files[i];
				test_files[i] = test_files[j];
				test_files[j] = buf;
			}
			j++;
		}
		i++;
	}
}
