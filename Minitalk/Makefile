# FLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a

all: 
	@make -C libft
	@cc $(FLAGS) sever.c $(LIBFT) -o server
	@echo  "server done [ ✅ ]" 
	@cc $(FLAGS) cliient.c $(LIBFT) -o client
	@echo  "client done [ ✅ ]" 
clean:
	@make fclean -C libft
	@rm -f  server
	@rm -f  client


re: clean all