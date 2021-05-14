/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 13:27:23 by msessa            #+#    #+#             */
/*   Updated: 2021/04/28 15:50:04 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_write_pos_nb(int n, int fd)
{
	char	c;

	if (n > 9)
		ft_write_pos_nb(n / 10, fd);
	c = '0' + (n % 10);
	write(fd, &c, 1);
}

static void	ft_write_neg_nb(int n, int fd)
{
	char	c;

	if (n < -9)
		ft_write_neg_nb(n / 10, fd);
	c = '0' - (n % 10);
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	neg;

	if (n < 0)
	{
		neg = '-';
		write(fd, &neg, 1);
		ft_write_neg_nb(n, fd);
	}
	else
		ft_write_pos_nb(n, fd);
}
