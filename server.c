/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:31 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/07 18:11:30 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*binumb;
int		clientpid;
int		j;

void	handle_sigusr(int signal, siginfo_t *info, void *context);

int main (void)
{
	unsigned int	pid;
	char			c;
	struct			sigaction sa;

	j = 0;
	c = 'a';
	binumb = ft_calloc(1, 9);
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
	static int	i;
	char		c;
	
	clientpid = info->si_pid;
	if (signal == SIGUSR1)
	{
		binumb[i] = '0';
//		printf("O vetor recebeu 0\n");
//		printf("O vetor agora é > |%s|\n", binumb);
		i++;
	}
	else
	{
		binumb[i] = '1';
//		printf("O vetor recebeu 1\n");
//		printf("O vetor agora é > |%s|\n", binumb);
		i++;
	}
	if (i == 8)
	{
		c = ((char)ft_batoi(binumb));
		write(1, &c, 1);
		i = 0;
	}
}
