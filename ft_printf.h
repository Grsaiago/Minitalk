/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 14:27:23 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/23 17:02:19 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

int				ft_printf(const char *s, ...);
int				ft_putstr(char *s);
int				ft_printhex(const char *base, unsigned int b, unsigned int n);
unsigned int	ft_printptr(const char *base, void *n);
int				ft_putnbr(int nbr);
int				ft_putchar(int c);

#endif
