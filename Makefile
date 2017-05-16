NAME = ft_ls

CC = gcc

CCFLAGS = -Wall -Werror -Wextra -g -O0 -L./libft -lftprintf

SRC = src/ls_addnode.c src/ls_clrtree.c src/ft_ls.c src/ls_init.c \
		src/ls_parse.c src/ls_puttree.c src/ls_treesrch.c src/ls_lmeta.c \
		src/ls_dirjoin.c src/ls_recurse.c
OBJ = *.o

RM = -rm -fr

HEADER = ft_ls.h

$(NAME):
		$(MAKE) -C ~/code/libft/
		$(CC) $(CCFLAGS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)
