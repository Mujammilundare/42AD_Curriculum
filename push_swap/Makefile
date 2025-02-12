# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mundare <mundare@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/08 13:21:45 by mundare           #+#    #+#              #
#    Updated: 2025/02/12 20:46:02 by mundare          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	push_swap.c \
		push_swap_utils.c \
		push_swap_libft_utils.c \
		push_swap_list_utils.c \
		push_swap_mem_utils.c \
		push_swap_sorting.c \
		push_swap_sorting2.c \
		push_swap_sorting3.c \
		push_swap_error_utils.c \

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re