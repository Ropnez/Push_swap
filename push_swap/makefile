NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	push_swap.c \
		rules_1.c \
		rules_2.c \
		rules_3.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		sort_1.c \
		sort_2.c \
		sort_3.c 



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