NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	push_swap.c \
		rules.c



OBJS =  $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

all: $(NAME)


clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re