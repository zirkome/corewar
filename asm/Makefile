##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Wed Mar 13 23:27:11 2013 nicolas bridoux
##

SRCS	=	main.c \
		op.c \
		my_putchar.c \
		my_string.c \
		read_fd.c \
		my_parsing.c \
		my_list.c \
		my_free.c \
		make_header.c \
		fill_name_and_comment.c \
		make_instruction_tab.c \
		check_command_label.c \
		check_instruct.c \
		write_commands.c \
		replace_label.c \
		cmd_pointer_tab.c \
		instruct_ld_lld.c \
		instruct_add_sub.c \
		instruct_and_or_xor.c \
		instruct_zjmp_live.c \
		instruct_ldi_lldi.c \
		instruct_fork_lfork.c \
		instruct_sti_st.c \
		make_compile.c \
		compilation_errors.c\
		change_endian.c\

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