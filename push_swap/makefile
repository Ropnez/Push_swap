NAME = push_swap
B_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

SRC =	push_swap.c \
		rules_1.c \
		rules_2.c \
		rules_3.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		utils_4.c \
		sort_1.c \
		sort_2.c \
		sort_3.c 

BONUS = checker.c \
		rules_1.c \
		rules_2.c \
		rules_3.c \
		utils_1.c \
		utils_2.c \
		utils_3.c \
		utils_4.c \
		sort_1.c \
		sort_2.c \
		sort_3.c 

OBJS =  $(SRC:.c=.o)
B_OBJS = $(BONUS:%.c=%.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft

$(B_NAME): $(B_OBJS) $(LIBFT)
	@$(CC) -o $(B_NAME) $(B_OBJS)  -L$(LIBFT_DIR) -lft

$(LIBFT):
	@make -C $(LIBFT_DIR)


%.o: %.c
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@

all: $(NAME)

bonus: $(B_NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJS) $(B_OBJS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME) $(B_NAME)

re: fclean all

.PHONY: all clean fclean re bonus