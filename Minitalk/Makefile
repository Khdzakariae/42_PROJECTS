# FLAGS = -Wall -Wextra -Werror
LIBFT = Mandatory/libft/libft.a


all: 
	@make -C Mandatory/libft
	@cc $(FLAGS) Mandatory/sever.c $(LIBFT) -o server
	@echo  "server done [ ✅ ]" 
	@cc $(FLAGS) Mandatory/cliient.c $(LIBFT) -o client
	@echo  "client done [ ✅ ]"
bonus:
	@make -C Mandatory/libft
	@cc $(FLAGS) bonus_part/client_bonus.c $(LIBFT) -o client_bonus
	@echo  "client done [ ✅ ]" 
	@cc $(FLAGS) bonus_part/server_bonuc.c $(LIBFT) -o server_bonus
	@echo  "server done [ ✅ ]" 

clean:
	@make fclean -C Mandatory/libft
	@rm -f  server
	@rm -f  client
	@rm -f  server_bonus
	@rm -f  client_bonus
	@echo  "clean [ ✅ ]" 




re: clean all