##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Mon Jan 21 18:33:09 2013 nicolas bridoux
##

SRCS	=	main.c\
		read_fd.c\
		my_putchar.c\
		my_string.c\

NAME	= 	asm

OBJS	=	$(SRCS:.c=.o)

CC	= 	gcc -g

CFLAGS	= 	-Wall -Wextra -pedantic -ansi

RM	=	rm -f

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all