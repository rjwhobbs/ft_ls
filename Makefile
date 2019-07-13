NAME = ft_ls

SRC = main.c process_args.c

OBJ = main.o process_args.o

CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ libft.a
	gcc $(CFLAGS) $(OBJ) $(LIB) -o $(NAME)

libft:
	make -C libft/ libft.a

clean:
	make -C libft/ clean
	rm -fr $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -fr $(NAME)

re: fclean all
