NAME = philo

SRC = main.c \
	error.c \
	ft.c \
	free.c \
	init.c \
	parsing.c \
	threads.c \

DIR 		= ${addprefix srcs/,${SRC}}

CC			= gcc

DEBUG		= -g

CFLAGS		= -Wall -Werror -Wextra -pthread $(DEBUG)

OBJS		= ${DIR:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) 

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re