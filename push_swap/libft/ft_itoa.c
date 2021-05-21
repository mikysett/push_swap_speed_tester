/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:31:57 by msessa            #+#    #+#             */
/*   Updated: 2021/03/23 11:45:29 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set_digits(int n)
{
	int	digits;

	digits = 1;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_save_pos_nb(char *res, int n, int digits)
{
	res[digits] = '0' + (n % 10);
	n /= 10;
	while (n != 0)
	{
		*(res + --digits) = '0' + (n % 10);
		n /= 10;
	}
}

static void	ft_save_neg_nb(char *res, int n, int digits)
{
	res[digits] = '0' - (n % 10);
	n /= 10;
	while (n != 0)
	{
		*(res + --digits) = '0' - (n % 10);
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		digits;
	int		neg;

	digits = ft_set_digits(n / 10);
	if (n < 0)
		neg = 1;
	else
		neg = 0;
	res = malloc(sizeof(char) * (digits + neg + 1));
	if (!res)
		return (0);
	if (!neg)
		ft_save_pos_nb(res, n, digits - 1);
	else
	{
		*res = '-';
		ft_save_neg_nb(res, n, digits);
	}
	res[digits + neg] = '\0';
	return (res);
}
