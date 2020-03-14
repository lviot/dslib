##
## LOUIS VIOT, 2020
## dslib
## File description:
## Makefile
##

NAME	=	libds.a
T_NAME	=	unit_tests

CC		=	gcc

RM		=	rm -f

SRCS	=	./srcs/generic.c				\
			./srcs/linked_list.c			\
			./srcs/getters.c				\
			./srcs/insert.c					\
			./srcs/remove.c					\
			./srcs/tools.c

TESTS	=	./tests/node.c					\
			./tests/linked_list_insertion.c	\
			./tests/null_ptr_param.c		\
			./tests/basic_getters.c			\
			./tests/basic_remove.c			\
			./tests/basic_tools.c			\
			$(SRCS)

OBJS	=	$(SRCS:.c=.o)

T_OBJS	=	$(TESTS:.c=.o)

CFLAGS	=	-Werror -Wextra -Wall
CFLAGS	+=	-I./headers

all:	$(NAME)

$(NAME):	$(OBJS)
	ar -rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	$(RM) $(T_OBJS)
	$(RM) *.gcda *.gcno

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(T_NAME)

tests: 	fclean $(TESTS)
	gcc -o $(T_NAME) $(TESTS) -lcriterion --coverage -I./headers
	./$(T_NAME)

coverage:	tests
	gcovr --exclude tests --branches

re: fclean all

.PHONY: all clean fclean tests re