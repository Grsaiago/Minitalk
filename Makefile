#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/09 11:08:06 by gsaiago           #+#    #+#              #
#    Updated: 2022/08/10 12:27:12 by gsaiago          ###   ########.fr        #
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

# Bonus Section #
CLIENT_BONUS	= client_bonus

SERVER_BONUS	= server_bonus

SRCSERVER_BONUS	= server_bonus.c

SRCCLIENT_BONUS	= client_bonus.c

SRCUTILS_BONUS	= utils_minitalk_bonus.c

OBJSERVER_BONUS	= $(SRCSERVER_BONUS:.c=.o)

OBJCLIENT_BONUS	= $(SRCCLIENT_BONUS:.c=.o)

OBJUTILS_BONUS	= $(SRCUTILS_BONUS:.c=.o)

RM = rm -f
FLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME) 

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):	$(OBJCLIENT) $(OBJUTILS) minitalk.h
	$(CC) $(FLAGS) $(OBJCLIENT) $(OBJUTILS) -o $(CLIENT)

$(SERVER):	$(OBJSERVER) minitalk.h
	$(CC) $(FLAGS) $(OBJSERVER) $(OBJUTILS) -o $(SERVER)

clean:
	rm -f $(OBJSERVER) $(OBJCLIENT) $(OBJUTILS) $(OBJSERVER_BONUS) $(OBJCLIENT_BONUS) $(OBJUTILS_BONUS)

fclean: clean
	rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS) 

re: fclean all

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):	$(OBJCLIENT_BONUS) $(OBJUTILS_BONUS) minitalk_bonus.h
	$(CC) $(FLAGS) $(OBJCLIENT_BONUS) $(OBJUTILS_BONUS) -o $(CLIENT_BONUS)

$(SERVER_BONUS):	$(OBJSERVER_BONUS) minitalk_bonus.h
	$(CC) $(FLAGS) $(OBJSERVER_BONUS) $(OBJUTILS_BONUS) -o $(SERVER_BONUS)

.PHONY: all clean fclean re bonus
