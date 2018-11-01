CC= gcc

NAME = BSQ

SRCS =	src/main.c \
		src/string.c \
		src/map.c \
		src/fill_array.c

OBJS = $(SRC:.c=.o)

FLAGS = -Iincludes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(SRCS) $(FLAGS)
	
clean:
	rm $(OBJS)
	
fclean:
	rm $(OBJS) $(NAME)
	
re: fclean all
	