CoreWar
==============

Projet CoreWar

#Usage
```sh
$ make
$ echo ./corewar [-comment] [-dump nbr_cycle] [[-n prog_number] [-a load_address ] prog_name] ...
```

## TODO
- Parser
- Penser à read de sizeof(header_t) pour check header + verif retour de read
- Instructions (live, ld, st, add, sub, and, or, xor, zjmp, ldi, sti, fork, lld, lldi, lfork, aff)
- CHECK corewar valide mais sans instruction non fonctionnelle
- CHECK #define DEBUG

 valgrind --log-file=log_valgrind4 ./corewar src2/3615sleep.cor src/tdc4.cor src2/42.cor src2/win98.cor
