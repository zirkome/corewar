##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Tue Jan 22 14:26:27 2013 nicolas bridoux
##

NAME	= asm

CC	= gcc -g

RM	= rm -f

LPATH	= ../lib

SRCS	= main.c			\

LSRCS	= $(LPATH)/my_putchar.c		\
	  $(LPATH)/my_string.c		\
	  $(LPATH)/read_fd.c		\

OBJS	= $(SRCS:.c=.o)

LOBJS	= $(LSRCS:.c=.o)

CFLAGS	+= -Wall -Wextra -pedantic
CFLAGS	+= -I../lib/include

$(NAME): $(OBJS) $(LOBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LOBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(LOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
