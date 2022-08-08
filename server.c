/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:31 by gsaiago           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/08/08 16:01:52 by gsaiago          ###   ########.fr       */
=======
/*   Updated: 2022/08/08 16:57:32 by gsaiago          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int main (void)
{
	struct			sigaction sa;

	sa.sa_sigaction = &handle_sigusr;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL); 
	ft_printf("O PID do server é > %d\n", getpid());
	while (1)
	{
		pause();
	}
}

void	handle_sigusr(int signal, siginfo_t *info, void *context)
{
	static int			i;
	static unsigned int	c;

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
