# Project Configuration
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -Iincludes -Ilibft

# Source Files
SRC			= src/main.c \
			  src/parsing/parse_args.c \
			  src/parsing/error_checks.c \
			  src/instruction/ft_push.c \
			  src/instruction/ft_reverse_rotate.c \
			  src/instruction/ft_rotate.c \
			  src/instruction/ft_swap.c \
			  algo/sort_large.c \
			  algo/sort_small.c \
			  utils/stack_utils.c \
			  utils/index_utils.c \
			  utils/check_utils.c \
			  utils/free_utils.c \
			  utils/sort_utils.c \

# Object Files
OBJ			= $(SRC:.c=.o)

# Libft Configuration
LIBFT		= libft/libft.a

# Build Rules
all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
			@$(MAKE) -C libft

%.o: %.c
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Clean Rules
clean:
			@$(MAKE) -C libft clean
			@rm -f $(OBJ)

fclean:		clean
			@$(MAKE) -C libft fclean
			@rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re