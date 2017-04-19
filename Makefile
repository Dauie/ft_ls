NAME = ft_ls

CC = gcc

CCFLAGS = -Wall -Werror -Wextra -O3 -L./libft -lftprintf 

SRC = src/addtnode.c src/cleartree.c src/ft_ls.c src/lserror.c src/lsinit.c \
		src/lsis.c src/lstick.c src/printtree.c src/treesearch.c
OBJ = *.o

RM = -rm -fr

HEADER = ft_ls.h

$(NAME):
		$(MAKE) -C libft/
		$(CC) $(CCFLAGS) $(SRC)

clean:
		$(RM) $(OBJ)

fclean:clean
		$(RM) $(NAME)

re:fclean $(NAME)
