NAME = push_swap
NAME_BONUS = checker

FLAGS = -Wall -Wextra -Werror

SRC_PUSH_SWAP = sources/push_swap_main.c sources/error_handling.c sources/argument_parser.c sources/action/sa_sb_ss_.c \
    sources/action/pa_pb.c sources/action/ra_rb_rr_.c sources/action/rra_rrb_rrr.c sources/searching.c \
    sources/sort_functions.c sources/utility_functions.c sources/number_sorting.c sources/get_next_line/get_next_line.c \
    sources/get_next_line/get_next_line_utils.c

SRC_CHECKER = bonus/checker.c sources/error_handling.c sources/argument_parser.c sources/action/sa_sb_ss_.c \
    sources/action/pa_pb.c sources/action/ra_rb_rr_.c sources/action/rra_rrb_rrr.c sources/searching.c \
    sources/sort_functions.c sources/utility_functions.c sources/number_sorting.c sources/get_next_line/get_next_line.c \
    sources/get_next_line/get_next_line_utils.c

LIBFT = sources/libft/libft.a
FT_PRINTF = sources/ft_printf/libftprintf.a

all: lib $(NAME)
	@echo "push_swap done [ ✅ ]"

bonus: lib $(NAME_BONUS)
	@echo "push_swap_bonus done [ ✅ ]"

$(NAME_BONUS): $(SRC_CHECKER)
	@cc $^ $(FLAGS) $(LIBFT) $(FT_PRINTF) -o checker

$(NAME): $(SRC_PUSH_SWAP)
	@cc $^ $(FLAGS) $(LIBFT) $(FT_PRINTF) -o push_swap

lib:
	@make -C sources/ft_printf --no-print-directory
	@make -C sources/libft --no-print-directory

clean:
	@make clean -C sources/ft_printf --no-print-directory
	@make clean -C sources/libft --no-print-directory
	@echo "clean [ ✅ ]"

fclean: clean
	@make fclean -C sources/ft_printf --no-print-directory
	@make fclean -C sources/libft --no-print-directory
	@rm -f push_swap checker
	@echo "fclean [ ✅ ]"

re: fclean all
