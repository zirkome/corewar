##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Sun Mar 31 05:52:32 2013 guillaume fillon
##

all: corewar asm

asm:
	make -Casm

corewar:
	make -Ccorewar

clean:
	make clean -Ccorewar
	make clean -Casm

fclean:
	make fclean -Ccorewar
	make fclean -Casm

re:
	make re -Ccorewar
	make re -Casm

.PHONY: all clean fclean re asm corewar
