# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dberehov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 14:46:09 by dberehov          #+#    #+#              #
#    Updated: 2023/05/20 14:46:12 by dberehov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
FLAGS = -Wall -Wextra -Werror
MAKEFLAG = --no-print-directory

# Colours
BGRED   = \033[0;41m
BGREEN   = \033[0;42m
BGYELL   = \033[0;43m
BGBLUE   = \033[0;44m
BGPURP   = \033[0;45m
BGCYAN   = \033[0;46m
NC     = \033[0m

# Executable name
SERVER = server
CLIENT = client

# Executable bonus name
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

# Required Libraries
LIBFT = libft/libft.a

# Project files - Server
SERVER_SOURCES = source/server.c source/utils.c
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

# Project files - Client
CLIENT_SOURCES = source/client.c source/utils.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

# Bonus project files - Server
SERVER_BONUS_SOURCES = source_bonus/server_bonus.c source/utils.c
SERVER_BONUS_OBJECTS = $(SERVER_BONUS_SOURCES:.c=.o)

# Bonus project files - Client
CLIENT_BONUS_SOURCES = source_bonus/client_bonus.c source/utils.c
CLIENT_BONUS_OBJECTS = $(CLIENT_BONUS_SOURCES:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJECTS) $(LIBFT)
	@printf "$(BGCYAN) Compiling server... $(NC)\n"
	$(CC) $(FLAGS) $(SERVER_OBJECTS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS) $(LIBFT)
	@printf "$(BGCYAN) Compiling client... $(NC)\n"
	$(CC) $(FLAGS) $(CLIENT_OBJECTS) $(LIBFT) -o $(CLIENT)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_BONUS_OBJECTS) $(LIBFT)
	@printf "$(BGCYAN) Compiling server bonus... $(NC)\n"
	$(CC) $(FLAGS) $(SERVER_BONUS_OBJECTS) $(LIBFT) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(CLIENT_BONUS_OBJECTS) $(LIBFT)
	@printf "$(BGCYAN) Compiling client bonus... $(NC)\n"
	$(CC) $(FLAGS) $(CLIENT_BONUS_OBJECTS) $(LIBFT) -o $(CLIENT_BONUS)

$(LIBFT):
	@printf "$(BGCYAN) Compiling Libft... $(NC)\n"
	@$(MAKE) $(MAKEFLAG) -C libft/

clean:
	@printf "$(BGYELL) Deleting created objects... $(NC)\n"
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	rm -f $(SERVER_BONUS_OBJECTS) $(CLIENT_BONUS_OBJECTS)
	@make --no-print-directory clean -C libft

fclean: clean
	@printf "$(BGYELL) Deleting executables... $(NC)\n"
	rm -f $(SERVER) $(CLIENT)
	rm -f $(SERVER_BONUS) $(CLIENT_BONUS)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re