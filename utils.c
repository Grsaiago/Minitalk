/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:19 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/08 15:50:21 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_calloc(size_t count, size_t size);

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	n;
	size_t	i;
		
	if (count == 0 || size == 0)
		return (NULL);
	i = -1;
	n = count * size;
	ptr = malloc(n);
	if (ptr == NULL)
		return (NULL);
	while (++i < n)
		((char *)ptr)[i] = 0;
	return (ptr);
}

void sendchar(int pid, unsigned int usecs, char c)
{
	int i;

	i = 8;
	while (i--)
	{
		if (!(c & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(usecs);
	}
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
