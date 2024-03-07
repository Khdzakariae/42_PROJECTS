# FLAGS = -Wall -Wextra -Werror
LIBFT = Mandatory/libft/libft.a


all: 
	@make -C Mandatory/libft
	@cc $(FLAGS) Mandatory/sever.c $(LIBFT) -o server
	@echo  "server done [ ok ]" 
	@cc $(FLAGS) Mandatory/cliient.c $(LIBFT) -o client
	@echo  "client done [ ok ]"
Bonus:
	@cc $(FLAGS) bonus/client_bonus.c $(LIBFT) -o client_bonus
	@echo  "client done [ ok ]" 
	@cc $(FLAGS) bonus/server_bonuc.c $(LIBFT) -o server_bonus
	@echo  "server done [ ok ]" 

clean:
	@make fclean -C Mandatory/libft
	@rm -f  server
	@rm -f  client
	@rm -f  server_bonus
	@rm -f  client_bonus



re: clean all