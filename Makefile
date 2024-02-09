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
			src/sorting/algo_station.c \
			src/sorting/sort_me.c \
			src/sorting/use_to_sort.c \
			src/stack/behavior.c \
			src/stack/tools.c \
			src/stack/indexing.c \

SRCSB	= src/bonus/checker_bonus.c


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