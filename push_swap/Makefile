NAME = push_swap

SRCS = push_swap_utils1.c error.c push_swap_utils2.c \
       push_swap_utils3.c radix_sort.c other_sort.c \
	   ft_lst.c moves.c push_swap_utils.c main.c \
	   push_swap_utils4.c moves2.c

OBJS = $(SRCS:.c=.o)

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