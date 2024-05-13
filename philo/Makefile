NAME = philo

FLAGS = -Wall -Wextra -Werror

SRC_PHILO = philo_main.c


all: $(NAME)
	@echo "philo done [ ✅ ]"


$(NAME): $(SRC_PHILO)
	@cc $^ $(FLAGS) -o philo

clean:
	@echo "clean [ ✅ ]"

fclean: clean
	@rm -f philo
	@echo "fclean [ ✅ ]"

re: fclean all
