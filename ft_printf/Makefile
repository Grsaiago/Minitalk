# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/22 14:34:49 by gsaiago           #+#    #+#              #
#    Updated: 2022/08/08 17:38:42 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = server.c\
	   utils.c\
	   clinet.c\

OBJS = $(SRCS:.c=.o)
RM = rm -f
ARC = ar -qs
FLAGS = -Wall -Werror -Wextra -c
CC = cc
LIBD = ./ft_printf/libft/

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
