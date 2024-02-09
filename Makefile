NAME	= push_swap
BONUS_NAME = checker
LIBFT = libft.a
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
INCLUDE = -I includes

SRCS	= src/parsing.c src/push_swap.c \
			src/operations/swap.c \
			src/operations/push.c \
			src/operations/rotate.c \
			src/operations/reverse_rotate.c \
			src/sorting_utils/sorting_algo_0.c \
			src/sorting_utils/sorting_algo_1.c \
			src/sorting_utils/sorting_algo_2.c \
			src/stack_utils/behavior.c \
			src/stack_utils/tools.c \
			src/stack_utils/indexing.c \

SRCSB	= src/bonus/checker.c


OBJS	= $(SRCS:.c=.o)
OBJSB	= $(SRCSB:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft
	@mv libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) $(LIBFT) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJSB)
	@make -C libft
	@mv libft/libft.a .
	@$(CC) $(CFLAGS) $(OBJSB) $(INCLUDE) $(LIBFT) -o $(BONUS_NAME)

clean:	
	@make clean -C libft
	@$(RM) $(OBJS) $(OBJSB)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME) $(BONUS_NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re bonus