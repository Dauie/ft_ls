NAME = ft_ls

CC = gcc

CCFLAGS = -Wall -Werror -Wextra -g -O0 -L./libft -lftprintf

SRC = src/ft_ls.c src/ls_initstructs.c src/ls_parse.c

OBJ = *.o

RM = -rm -fr

$(NAME):
		$(MAKE) -C ./libft/ re
		$(CC) $(CCFLAGS) $(SRC) -o $(NAME)

clean:
		$(RM) $(OBJ)

fclean: clean
		$(RM) $(NAME)

re: fclean $(NAME)
