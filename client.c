/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:54:58 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/05 19:00:37 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	unsigned int	pid;
	char			*ptr;
	unsigned int	usecs;
	struct 			sigaction sa;

	if (argc > 3)
	{
			printf("Excesso de argumentos");
			return (-1);
	}
	usecs = 100;
	i = 0;
	pid = atoi(argv[1]);
	ptr = argv[2];
	printf("o pid recebido foi > %d\n", pid);
	while(ptr[i])
	{
		sendchar(pid, usecs, ptr[i]);
		i++;
	}
	printf("PID do client é > %d", getpid());
}
