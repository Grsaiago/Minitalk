/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 13:54:58 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/09 18:54:31 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned int	g_wc;

void	handle_sigusr_c(int signal);

int	main(int argc, char *argv[])
{
	int					i;
	int					pid;
	char				*ptr;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "O input correto é \"<PID> <string>\"\n", 37);
		return (-1);
	}
	signal(SIGUSR1, &handle_sigusr_c);
//	sigaction(SIGUSR1, &sa, NULL);
//	sa.sa_handler = &handle_sigusr_c;
//	sa.sa_flags = 0;
//	sigemptyset(&sa.sa_mask);
//	sigaddset(&sa.sa_mask, SIGUSR1);
//	sigaddset(&sa.sa_mask, SIGUSR2);
	g_wc = 0;
	i = -1;
	pid = ft_atoi(argv[1]);
	ptr = argv[2];
	while (ptr[++i])
		sendchar(pid, 250, ptr[i]);
	sendchar(pid, 250, '\0');
	pause();
}

void	handle_sigusr_c(int signal)
{
	write(1, "O total enviado foi: ", 21);
	writenbr(g_wc);
	write (1, "\n", 1);
}

void	sendchar(int pid, unsigned int usecs, char c)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (!(c & (1 << i)))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(usecs);
	}
	g_wc++;
}
