/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:54:58 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/08 16:04:43 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	wc;


void	handle_sigusr_c (int signal);

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	unsigned int	pid;
	char			*ptr;
	unsigned int	usecs;
	struct 			sigaction sa;
	
	wc = 0;
	if (argc > 3)
	{
			printf("Excesso de argumentos");
			return (-1);
	}
	sa.sa_handler = &handle_sigusr_c;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	usecs = 500;
	i = 0;
	pid = atoi(argv[1]);
	ptr = argv[2];
	printf("o pid recebido foi > %d\n", pid);
	while(ptr[i])
	{
		sendchar(pid, usecs, ptr[i]);
		i++;
	}
	sendchar(pid, usecs, '\0');
	printf("PID do client é > %d", getpid());
}

void	handle_sigusr_c (int signal)
{
	write(1, "O total enviado foi: ", 21);
	writenbr(wc);
	write (1, "\n", 1);
}
