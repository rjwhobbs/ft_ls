NAME = ft_ls

SRC = main.c process_args.c sort.c get_filenames.c count_files.c\
	  count_dirs.c get_dirnames.c print_files.c\
	  print_R.c print_files_l.c strstr_del.c\
	  print_name.c printdirname.c sort_time.c print_sym_link.c\
	  print_file_l.c

OBJ = main.o process_args.o sort.o get_filenames.o count_files.o\
	  count_dirs.o get_dirnames.o print_files.o\
	  print_R.o print_files_l.o strstr_del.o\
	  print_name.o printdirname.o sort_time.o print_sym_link.o\
	  print_file_l.o

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
