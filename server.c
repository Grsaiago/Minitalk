/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:31 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/08 14:07:06 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr(int signal, siginfo_t *info, void *context);

int main (void)
{
	unsigned int	pid;
	struct			sigaction sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("O PID é > %d\n", getpid());
	while (1)
	{
		pause();
	}
}

void	handle_sigusr(int signal, siginfo_t *info, void *context)
{
	static int		i;
	unsigned int	c;
	unsigned int	clientpid;

	if (signal == SIGUSR1)
	{
		c = c << 1;
		i++;
	}
	else
	{
		c = c << 1;
		c = c | 1;
		i++;
	}
	if (i == 8)
	{
		if (c == '\0')
			kill(info->si_pid, SIGUSR1);
		write(1, &c, 1);
		i = 0;
	}
}
