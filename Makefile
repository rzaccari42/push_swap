# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: razaccar <razaccar@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 17:08:37 by razaccar          #+#    #+#              #
#    Updated: 2024/05/28 10:55:03 by razaccar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = $(wildcard src/move_set/*.c) $(wildcard src/sorting_process/*.c) \
	  $(wildcard src/utils/*.c)
OBJ = $(SRC:.c=.o)

INCLUDES = -I include -I libft/include

CC = gcc
CFLAGS = -fsanitize=address -g -Wall -Wextra -Werror 
LIB = ar rc
REMOVE = rm -f

green := \033[0;32m

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/ 
	$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $(NAME)
	@echo "$(green)$(NAME) program compiled."

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft/ fclean
	$(REMOVE) $(OBJ)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
