NAME = philo
CC = cc 
CFLAGS = -Wall -Wextra -Werror -g
INC_DIR = includes
SRCS = srcs/main.c \
		srcs/ft_atoi.c \
		srcs/parser.c
OBJS = $(SRCS:.c=.o)
LIBS = -pthread
HEADERS = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBS) -I$(INC_DIR)/philo.h -o $(NAME)

$(OBJS): %.o: %.c $(INC_DIR)/philo.h 
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re