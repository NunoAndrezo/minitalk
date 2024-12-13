#Variables (Executable names):
NAME_C = client
NAME_S = server
#Library Commands:
LIBFT = cd libft && make
PRINTF = cd printf && make
CP = cp printf/libftprintf.a . && cp libft/libft.a .
#Library Names:
PRF = libftprintf.a
LIB = libft.a
#Source Files
SRC_C_FILES = client.c
SRC_S_FILES = server.c
#Object Files
OBJ_C = $(SRC_C_FILES:.c=.o)
OBJ_S = $(SRC_S_FILES:.c=.o)
#Compiler Settings
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all :
		$(PRINTF)
		$(LIBFT)
		$(CP)
		@make start

start: $(NAME_C) $(NAME_S)

$(NAME_C) : $(OBJ_C)
		$(CC) $(CFLAGS) $(OBJ_C) $(PRF) $(LIB) -o $(NAME_C)

$(NAME_S) : $(OBJ_S)
		$(CC) $(CFLAGS) $(OBJ_S) $(PRF) $(LIB) -o $(NAME_S)

clean:
		$(RM) $(OBJ_C) $(OBJ_S)
		$(PRINTF) clean
		$(LIBFT) clean

fclean: clean
			$(RM) $(NAME_C) $(NAME_S) $(PRF) $(LIB)
			$(LIBFT) fclean
			$(PRINTF) fclean

re:	fclean all

.PHONY:		all bonus clean fclean re
#.PHONY specifies targets that are not actual files.
#This helps ensure that make runs these commands when specified
#even if files with these names exist.
