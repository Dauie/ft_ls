NAME = ft_ls.a

CC = gcc

OBJ = *.o

ARCHIVE = ar rc

INDEX = ranlib

HEADER =

clean:
		$(RM) $(OBJ)

fclean:clean
		$(RM) $(NAME)

re:fclean $(NAME)
