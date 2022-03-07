/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deleusis <deleusis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:31:17 by deleusis          #+#    #+#             */
/*   Updated: 2022/02/22 18:00:03 by deleusis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fn2(char *str, int *i, int n, int sign)
{
	while (n != 0)
	{	
		str[--(*i)] = (char)((n % 10) * sign + '0');
		n = n / 10;
	}
}

static int	ft_get_count(int num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		sign;

	i = ft_get_count(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	i = i + (n <= 0);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	if (n == 0)
	{
		str [0] = '0';
		str [1] = '\0';
		return (str);
	}
	str[i] = '\0';
	ft_fn2(str, &i, n, sign);
	i--;
	if (sign < 0)
		str[i] = '-';
	return (str);
}
