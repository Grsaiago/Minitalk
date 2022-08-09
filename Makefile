# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 11:08:06 by gsaiago           #+#    #+#              #
#    Updated: 2022/08/09 17:38:25 by gsaiago          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk

CLIENT	= client

SERVER	= server

SRCSERVER	= server.c

SRCCLIENT	= client.c

SRCUTILS	= utils_minitalk.c

OBJSERVER	= $(SRCSERVER:.c=.o)

OBJCLIENT	= $(SRCCLIENT:.c=.o)

OBJUTILS	= $(SRCUTILS:.c=.o)


RM = rm -f
FLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME) 

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):	$(OBJCLIENT) $(OBJUTILS) minitalk.h
	$(CC) $(FLAGS) $(OBJCLIENT) $(OBJUTILS) -o $(CLIENT)

$(SERVER):	$(OBJSERVER) minitalk.h
	$(CC) $(FLAGS) $(OBJSERVER) $(OBJUTILS) -o $(SERVER)

# $(OBJS): $(SRCS)
#	$(CC) -I . -c $(FLAGS) $(SRCS)

clean:
	rm -f $(OBJSERVER) $(OBJCLIENT) $(OBJUTILS)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
