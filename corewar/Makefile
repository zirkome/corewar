##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Tue Jan 29 04:12:24 2013 guillaume fillon
##

NAME	= corewar

CC	= clang

RM	= rm -f

LPATH	= ../lib

SRCS	= main.c			\
	  check_header.c		\
	  open_file.c			\
	  launch_vm.c			\
	  vm_utils.c			\
	  parser.c			\
	  free_champ.c			\
	  run_cycle.c			\
	  list/push.c			\
	  list/free_list.c		\
	  list/pop.c			\
	  list/create_list.c		\
	  instructions/live.c		\
	  instructions/ld.c		\
	  instructions/st.c		\
	  instructions/add.c		\
	  instructions/sub.c		\
	  instructions/and.c		\
	  instructions/or.c		\
	  instructions/xor.c		\
	  instructions/zjmp.c		\
	  instructions/ldi.c		\
	  instructions/sti.c		\
	  instructions/fork.c		\
	  instructions/lld.c		\
	  instructions/lldi.c		\
	  instructions/lfork.c		\
	  instructions/aff.c		\

LSRCS	= $(LPATH)/my_putchar.c		\
	  $(LPATH)/my_string.c		\
	  $(LPATH)/read_fd.c		\
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
