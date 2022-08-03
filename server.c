/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:55:31 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/03 17:55:43 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*binumb;

void	handle_sigusr(int signal);

int main (void)
{
	unsigned int	pid;
	char			c;
	struct			sigaction sa;
	int				count;
	count = 0;
	binumb = ft_calloc(1, 9);
	sa.sa_handler = &handle_sigusr;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("O PID é > %d\n", getpid());
	while (count < 7)
	{
		pause();
		count++;
	}
	c = ft_batoi(binumb);
	putchar(c);
}


void	handle_sigusr(int signal)
{
	static int i;

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
}
