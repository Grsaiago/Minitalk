/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:20:34 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/08 17:53:37 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

void	*ft_calloc(size_t count, size_t size);

void	writenbr(int nbr);

void	handle_sigusr(int signal, siginfo_t *info, void *context);

void 	sendchar(int pid, unsigned int usecs, char str);

void	handle_sigusr_c (int signal);

#endif
