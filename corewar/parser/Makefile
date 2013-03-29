##
## Makefile for makefile in /home/linard_f//corewar/homework/vm
## 
## Made by fabien linardon
## Login   <linard_f@epitech.net>
## 
## Started on  Thu Mar 21 10:26:07 2013 fabien linardon
## Last update Thu Mar 21 14:11:44 2013 remi
##

NAME	=	parse

SRC	=	main.c \
		parsing_param.c \
		fill_prog_tab.c \
		my_strcmp.c \
		progs_info.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -ansi

CC	=	gcc

RM	=	rm -f

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all