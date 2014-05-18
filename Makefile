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
