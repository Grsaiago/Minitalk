/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:20:34 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/10 17:31:47 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	writenbr(int nbr);

void	handle_sigusr(int signal, siginfo_t *info, void *context);

void	sendchar(int pid, unsigned int usecs, char str);

void	handle_sigusr_c(int signal);

int		ft_atoi(const char *str);

int		ft_pow10(int n);

int		ft_tatoi(const char *str, int sign);

#endif
