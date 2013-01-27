##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Sun Jan 27 00:50:02 2013 guillaume fillon
##

NAME	= corewar

CC	= clang

RM	= rm -f

LPATH	= ../lib

SRCS	= main.c			\
	  check_header.c		\
	  open_file.c			\
	  init_vm.c			\
	  parser.c			\
	  list/push.c			\
	  list/pop.c			\
	  list/create_list.c		\

LSRCS	= $(LPATH)/my_putchar.c		\
	  $(LPATH)/my_string.c		\
	  $(LPATH)/read_fd.c		\
	  $(LPATH)/utils.c		\
	  $(LPATH)/op.c			\

OBJS	= $(SRCS:.c=.o)

LOBJS	= $(LSRCS:.c=.o)

CFLAGS	+= -g -Wall -Werror
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
