NAME=libftprintf.a
# FLAGS = -Wall -Wextra -Werror
PRINTF_SRCS = *.c libft/*.c
OBJS = *.o

$(NAME):
	gcc -c $(PRINTF_SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)
	#libft.a

re: fclean all
