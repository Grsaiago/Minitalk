/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:19 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/07 18:09:30 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	ft_batoi(char *ptr);
size_t			ft_pow(size_t base, size_t exp);
void			*ft_calloc(size_t count, size_t size);

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

unsigned int ft_batoi(char *ptr)
{
	unsigned int	i;
	unsigned int	numb;

	numb = 0;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == '1')
		{
			numb += ft_pow(2, 7 - i);
			i++;
		}
		else
			i++;
	}
	return (numb);
}

size_t	ft_pow(size_t base, size_t exp)
{
	if (!exp)
		return (1);
	else if (!base)
		return (0);
	if (!exp)
			return (1);
	else
		return (base * ft_pow(base, exp - 1));
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
		usleep(100);
	}
}
