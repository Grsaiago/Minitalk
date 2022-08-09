# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 11:08:06 by gsaiago           #+#    #+#              #
#    Updated: 2022/08/09 14:17:58 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMECLIENT = client

NAMESERVER = server

UTILS = utils_minitalk.c

NAME = minitalk.a

SRCS = client.c\
	   server.c\
	   utils_minitalk.c\

OBJS = $(SRCS:.c=.o)

RM = rm -f
FLAGS = -Wall -Werror -Werror -c
CC = cc

all: $(NAME) 

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	$(CC) -I . -c $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
