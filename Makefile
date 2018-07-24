##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## connect 	all source files
##

NAME	= lemipc

CC	= gcc

RM	= rm -f

RMIPC	= ./rmipc

SRCS	= ./src/check_param.c \
	  ./src/create_sema.c \
	  ./src/main.c \
	  ./src/move.c \
	  ./src/utils_functions.c \
	  ./src/ia_file.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./header/

CFLAGS += -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RMIPC)

re: fclean all

.PHONY: all clean fclean re
