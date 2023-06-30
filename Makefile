# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrahovha <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 13:55:51 by hrahovha          #+#    #+#              #
#    Updated: 2023/05/11 13:55:52 by hrahovha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BUILD =	build

CC = cc

SRC = $(wildcard ps/*.c)

LIBFT = utils

OBJ = $(patsubst %.c, %.o, $(SRC))

A = $(patsubst %.o, $(BUILD)/%.o, $(OBJ))

CFLAGS = -Wall -Wextra -Werror

$(BUILD)/%.o: %.c Makefile
	@mkdir -p $(BUILD)/ps
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(A)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(A) -o $(NAME) -L./libft -lft

fclean: clean
	rm -rf $(NAME) $(BUILD)

clean:
	$(MAKE) clean -C $(LIBFT)
	rm -rf $(OBJ)

re: fclean all

.PHONY: all clean fclean re
