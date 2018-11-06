CC= gcc

NAME = BSQ

SRCS =	src/main.c \
		src/string.c \
		src/map.c \
		src/fill_array.c \
		src/solve.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Iincludes -g3

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS)
	
clean:
	rm $(OBJS)
	
fclean:
	rm $(OBJS) $(NAME)
	
re: fclean all
	