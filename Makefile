##
## Makefile for Makefile in /home/bridou_n//minishell1
## 
## Made by nicolas bridoux
## Login   <bridou_n@epitech.net>
## 
## Started on  Fri Nov  9 20:29:49 2012 nicolas bridoux
## Last update Tue Jan 22 12:51:59 2013 guillaume fillon
##

all: corewar asm

asm:
	make -Casm

corewar:
	make -Cvm

clean:
	make clean -Cvm
	make clean -Casm

fclean:
	make fclean -Cvm
	make fclean -Casm

re:
	make re -Cvm
	make re -Casm
