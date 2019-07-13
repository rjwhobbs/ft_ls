NAME = ft_ls

SRC = main.c process_args.c sort.c get_filenames.c count_files.c\
	  get_filenames_d.c

OBJ = main.o process_args.o sort.o get_filenames.o count_files.o\
	  get_filenames_d.o

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
