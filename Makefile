# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvasquez <mvasquez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/04 11:55:36 by mvasquez          #+#    #+#              #
#    Updated: 2026/04/06 17:49:29 by mvasquez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -f
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRCS        =	src/push_swap.c \
				src/parsing.c \
				src/stack_utils.c \
				src/utils.c \
				src/operations/push.c \
				src/operations/rev_rotate.c \
				src/operations/rotate.c \
				src/operations/swap.c \
				src/algorithm/sort.c \
				src/algorithm/turk_utils.c \
				src/algorithm/cost.c \
				src/algorithm/do_move.c \
				src/algorithm/turk_sort.c

OBJS        = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
