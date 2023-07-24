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

BONUS = checker

BUILD =	build

CC = cc

SRC = $(wildcard ps/*.c)

SRCB = $(wildcard ps_bonus/*.c)

UTILS = libft

OBJ = $(patsubst %.c, %.o, $(SRC))
OBJB = $(patsubst %.c, %.o, $(SRCB))

A = $(patsubst %.o, $(BUILD)/%.o, $(OBJ))
B = $(patsubst %.o, $(BUILD)/%.o, $(OBJB))

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

$(BUILD)/%.o: %.c Makefile
	@mkdir -p $(BUILD)/ps
	@mkdir -p $(BUILD)/ps_bonus
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

$(NAME): $(A)
	$(MAKE) -C $(UTILS)
	$(CC) $(CFLAGS) $(A) -o $(NAME) -L./libft -lft

$(BONUS): $(B)
	$(MAKE) -C $(UTILS)
	$(CC) $(CFLAGS) $(B) -o $(BONUS) -L./libft -lft

bonus: $(BONUS)

fclean: clean
	rm -rf $(NAME) $(BONUS) $(BUILD)

clean:
	$(MAKE) clean -C $(UTILS)
	rm -rf $(OBJ) $(OBJB)

re: fclean all

.PHONY: all clean fclean re bonus
