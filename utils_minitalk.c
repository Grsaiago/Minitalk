/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minitalk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:55:33 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/09 11:02:02 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int	sign;

	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '+' && str[1] >= '0' && str[1] <= '9')
		str++;
	else if (*str == '-' && str[1] >= '0' && str[1] <= '9')
	{
		str++;
		sign = -1;
	}
	if (*str >= '0' && *str <= '9')
		return (ft_tatoi(str, sign));
	return (0);
}

int	ft_tatoi(const char *str, int sign)
{
	int	len;
	int	i;
	int	max;
	int	numb;

	i = -1;
	len = 0;
	max = 0;
	numb = 0;
	while (str[len] >= '0' && str[len] <= '9')
		len++;
	max = len;
	while (++i < max)
		numb = numb + (str[i] - 48) * ft_pow10(--len);
	return (numb * sign);
}

int	ft_pow10(int n)
{
	int	base;
	int	i;

	i = -1;
	base = 1;
	while (++i < n)
		base = base * 10;
	return (base);
}

void	writenbr(int nbr)
{
	char	nb;
	long	n;

	if (nbr < 0)
	{
		n = (long) nbr * -1;
		write (1, "-", 1);
	}
	else
		n = (long) nbr;
	if (n < 10 && n >= 0)
	{
		nb = n + 48;
		write (1, &nb, 1);
		return ;
	}
	else
		writenbr(n / 10);
	writenbr(n % 10);
	return ;
}
