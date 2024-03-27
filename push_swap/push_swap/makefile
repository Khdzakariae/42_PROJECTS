
NAME = push_swap

# FLAGS = -Wall -Wextra -Werror


SRC = push_swap.c parcin/parisin1.c parcin/errores.c

LIBFT = libft/libft.a
FT_PRINTF = ft_printf/libftprintf.a

all: lib $(NAME)
	@echo  "push_swap done [ ✅ ]"  

$(NAME) : $(SRC)
	@cc $^ $(FLAGS)  $(LIBFT) $(FT_PRINTF) -o push_swap

lib :
	@make -C ft_printf --no-print-directory
	@make -C libft --no-print-directory

clean:
	@make clean -C ft_printf --no-print-directory
	@make clean -C libft --no-print-directory
	@echo  "clean [ ✅ ]" 

fclean : clean
	@make clean -C ft_printf --no-print-directory
	@make clean -C libft --no-print-directory
	@rm -f  push_swap
	@echo  "fclean [ ✅ ]" 

re: clean all
