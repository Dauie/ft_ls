NAME = ft_ls

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

SRC = src/ft_ls.c src/ls_add.c src/ls_addnode.c src/ls_compairtime.c src/ls_dirjoin.c src/ls_error.c src/ls_file.c src/ls_initstructs.c src/ls_list.c src/ls_metainfo.c src/ls_parse.c src/ls_put.c src/ls_traverse.c src/ls_recurse.c

OBJ = *.o

RM = -rm -fr

$(NAME):
		$(MAKE) -C ./libft/ re
		$(CC) $(CCFLAGS) $(SRC) ./libft/libftprintf.a -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)
