CoreWar
==============

Projet
-------
Projet CoreWar s'étalant sur 2 mois et demi, avec un groupe de 4 Membres composé de Fabien Linard (Chef de projet - Partie ASM), Nicolas Bridoux (Partie ASM), Rémi Robert (Partie VM), et Guillaume Fillon (Partie VM supplément SDL).

Core War est un jeu de programmation dans lequel deux programmes informatiques (ou plus) sont en concurrence pour le contrôle d'une machine virtuelle appelée MARS, pour Memory Array Redcode Simulator.
Ces programmes sont écrits en un Assembleur spécial CoreWar. Le but du jeu est de faire se terminer toutes les instances du (ou des) programme(s) adverse(s), de façon à ce que son programme soit le seul à s'exécuter.

Instructions pour l'assembleur
--------

| Mnémonique |                               Effets                        |
|:----------:| ----------------------------------------------------------- |
| 0x01 (live)|Suivie de 4 octets qui représente le numéro du joueur. Cette instruction indique que ce joueur est en vie. (pas d’octet de codage des paramètres).                                    |
|0x02 (ld)|Cette instruction prend 2 paramètres le deuxième est forcement un registre (pas le PC). Elle load la valeur du premier paramètre dans le registre. Cette opération modifie le carry. ``ld 34,r3`` charge les `REG_SIZE` octets a partir de l’adresse `(PC + (34 % IDX_MOD))` dans le registre r3.|
|0x03 (st)|Cette instruction prend 2 paramètres. Elle store (`REG_SIZE` octets) la valeur du premier argument (toujours un registre) dans le second. `st r4,34` store la valeur de r4 a l’adresse`(PC + (34 % IDX_MOD))`, `st r3,r8` copie r3 dans r8|
|0x04 (add)|Cette instruction prend 3 registres en paramètre, additionne le contenu des 2 premiers et met le résultat dans le troisième. Cette opération modifie le carry. `add r2,r3,r5` additionne r2 et r3 et mets le résultat dans r5|
|0x05 (sub)|Même que add mais soustrait|
|0x06 (and)|p1 & p2 -> p3 le paramètre 3 et toujours un registre. Cette opération modifie le carry. `and r2,%0,r3` met r2 & 0 dans r3|
|0x07 (or)|Même que and mais avec le ou (&#124; du c).|
|0x08 (xor)|Même que and mais avec le ou exclusif (^ du c).|
|0x09 (zjmp)|Cette instruction n’est pas suivie d’octet pour décrire les paramètres. Elle prend toujours un index (`IND_SIZE`) et fait un saut a cet index si le carry est à un. Si le carry est nul, zjmp ne fait rien mais consomme le même temps. `zjmp %23` met si carry == 1 met `(PC + (23 % IDX_MOD))` dans le PC.|
|0x0A (ldi)|Cette opération modifie le carry. `ldi 3,%4,r1` lit `IND_SIZE` octets à l’adresse : `(PC + (3 % IDX_MOD))` ajoute 4 à cette valeur. On nommera S cette somme. On lit `REG_SIZE` octets a l’adresse `(PC + (S % IDX_MOD))` qu’on copie dans r1. Les paramètre 1 et 2 sont des index.|
|0x0B (sti)|`sti r2,%4,%5` sti copie `REG_SIZE` octets de r2 a l’adresse `(4 + 5)`. Les paramètres 2 et 3 sont des index. Si les paramètres 2 ou 3 sont des registres, on utilisera leur contenu comme un index.|
0x0C (fork)|Cette instruction n’est pas suivie d’octet pour décrire les paramètres. Elle prend toujours un index et crée un nouveau programme qui s’exécute a partir de l’adresse:`(PC + (premier paramètre % IDX_MOD))`<br>`fork %34` crée un nouveau programme. Le nouveau programme hérite des différents états du père.|
0x0D (lld)|Comme ld sans le `%IDX_MOD` Cette opération modifie le carry.|
0x0E (lldi)|Comme ldi sans le `%IDX_MOD` Cette opération modifie le carry.|
0x0F (lfork)|Comme fork sans le `%IDX_MOD` Cette opération modifie le carry.|
0x10 (aff)|Cette instruction est suivi d’un octet de paramétrage pour décrire les paramètres. Elle prend en paramètre un registre et affiche le caractère dont le code ascii est présent dans ce registre. (un modulo 256 est applique au code ascii, le caractère est affiché sur la sortie standard).<br>Ex :` ld %42,r3` puis `aff r3` affiche ’*’ sur la sortie standard.|


Exemple de programme assembleur
------------
```asm
.name "zork"
.comment "just a basic living prog"

l2:     sti r1,%:live,%1
        and r1,%0,r1
live:   live %1
        zjmp %:live
```

Usage
------------
###Compilateur assembleur
```sh
make asm
echo ./asm file_name[.s] ...
```
###Machine Virtuel (SDL requise)
```sh
make corewar
echo ./corewar [-v] [-z][-dump nbr_cycle] [[-n prog_number] [-a load_address ] prog_name] ...
```
