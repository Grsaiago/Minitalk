/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:31 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/10 12:23:56 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "O PID do server é > ", 21);
	writenbr(getpid());
	write (1, "\n", 1);
	while (1)
		pause();
}

void	handle_sigusr(int signal, siginfo_t *info, void *context)
{
	static int			i;
	static unsigned int	c;

	c = c << 1;
	if (signal == SIGUSR2)
		c = c | 1;
	i++;
	if (i == 8)
	{
		if (c == 0)
		{
			kill(info->si_pid, SIGUSR1);
			sleep(1);
			kill(info->si_pid, SIGUSR2);
		}
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}
