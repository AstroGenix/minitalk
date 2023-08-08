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
NAME = 

# Required Libraries
LIBFT = libft/libft.a

# Project files
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
  @printf "$(BGCYAN) Compiling so_long... $(NC)\n"
  $(CC) $(OBJECTS) $(LIBFT)-o $(NAME)
  @printf "$(BGREEN) Compilation finished!! $(NC)\n"

$(OBJECTS_DIR): sources/%.c
  @printf "$(BGBLUE) Creating .o files... $(NC)\n"
  mkdir -p $(@D)
  $(CC) -I includes $(FLAGS) -c $< -o $@

$(LIBFT):
  @printf "$(BGCYAN) Compiling Libft... $(NC)\n"
  @$(MAKE) $(MAKEFLAG) -C libft/

clean:
  @printf "$(BGYELL) Deleting created objects... $(NC)\n"
  rm -f $(OBJECTS)
  @make --no-print-directory clean -C libft

fclean: clean
  @printf "$(BGYELL) Deleting executables... $(NC)\n"
  rm -f $(NAME)
  rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re