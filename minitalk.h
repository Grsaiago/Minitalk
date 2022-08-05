/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 17:20:34 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/05 17:51:55 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>

size_t	ft_batoi(char *ptr);

size_t	ft_pow(size_t base, size_t exp);

void	*ft_calloc(size_t count, size_t size);

void	handle_sigusr(int signal, siginfo_t *info, void *context);

void sendchar(int pid, unsigned int usecs, char str);

#endif
