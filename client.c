/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:54:58 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/03 17:52:34 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	unsigned int	pid;
	char			*ptr;

	i = 0;
	pid = atoi(argv[1]);
	ptr = argv[2];
	while(ptr[i])
	{
		j = 7;
		while (j >= 0)
		{
			if (!(ptr[i] & (1 << j)))
			{
				kill(pid, SIGUSR1);
				printf("o bit é 0\n");
			}
			else
			{
				kill(pid, SIGUSR2);
				printf("o bit é 1\n");
			}
			j--;
		}
		printf("---###---\n");
		i++;
	}
	//printf("o pid recebido foi > %d", pid);
}
