# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
<<<<<<< HEAD
#    Created: 2022/08/03 17:48:46 by gsaiago           #+#    #+#              #
#    Updated: 2022/08/03 17:49:08 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk.a
=======
#    Created: 2022/06/22 14:34:49 by gsaiago           #+#    #+#              #
#    Updated: 2022/06/23 16:30:15 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
>>>>>>> master

SRCS = ft_printf.c\
	   ft_putstr.c\
	   ft_printhex.c\
	   ft_printptr.c\
	   ft_putnbr.c\
	   ft_putchar.c\

OBJS = $(SRCS:.c=.o)
RM = rm -f
ARC = ar -qs
FLAGS = -Wall -Werror -Wextra -c
CC = cc
LIBD = libft/

.c.o:
	$(CC) $(FLAGS) -I $(LIBD) $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	cd $(LIBD) && make && cp libft.a ../$(NAME)
	$(ARC) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	cd $(LIBD) && make clean

fclean: clean
	$(RM) $(NAME)
	cd $(LIBD) && make fclean

re: fclean all

.PHONY: all re fclean clean
