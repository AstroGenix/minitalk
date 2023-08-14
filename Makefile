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

# Required Libraries
LIBFT = libft/libft.a

# Project files - Server
SERVER_SOURCES = source/server.c
SERVER_OBJECTS = $(SERVER_SOURCES:.c=.o)

# Project files - Client
CLIENT_SOURCES = source/client.c
CLIENT_OBJECTS = $(CLIENT_SOURCES:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJECTS) $(LIBFT)
	@printf "$(BGCYAN) Compiling server... $(NC)\n"
	$(CC) $(FLAGS) $(SERVER_OBJECTS) $(LIBFT) -o $(SERVER)

$(CLIENT): $(CLIENT_OBJECTS) $(LIBFT)
	@printf "$(BGCYAN) Compiling client... $(NC)\n"
	$(CC) $(FLAGS) $(CLIENT_OBJECTS) $(LIBFT) -o $(CLIENT)

$(LIBFT):
	@printf "$(BGCYAN) Compiling Libft... $(NC)\n"
	@$(MAKE) $(MAKEFLAG) -C libft/

clean:
	@printf "$(BGYELL) Deleting created objects... $(NC)\n"
	rm -f $(SERVER_OBJECTS) $(CLIENT_OBJECTS)
	@make --no-print-directory clean -C libft

fclean: clean
	@printf "$(BGYELL) Deleting executables... $(NC)\n"
	rm -f $(SERVER) $(CLIENT)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re