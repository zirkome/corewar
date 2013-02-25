/*
** sti.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:00 2013 guillaume fillon
** Last update Mon Feb 25 09:14:25 2013 remi robert
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"
/* Est censé marcher ... */
/* 3 min plus tard ... Oui ça marche !!*/

void		op_sti(t_vm *vm, t_proc **lproc)
{
  printf("%sSTI%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, 0, 0, 0);
  exit(0);
  /* if (lproc->cmd[1] > 16) */
  /*   { */
  /*     lproc->pc += 1; */
  /*     return ; */
  /*   } */
  /* if ((lproc->cmd[0] >> 4) & 0x03 == 1 && (lproc->cmd[0] >> 2) & 0x03 == 1) */
  /*   { */
  /*     if (lproc->cmd[2] > 16 && lproc->cmd[2] > 16) */
  /* 	{ */
  /* 	  lproc->pc += 1; */
  /* 	  return ; */
  /* 	} */
  /*     lproc->reg[(int)lproc->cmd[1]] = */
  /* 	vm->mem[(int)((lproc->reg[(int)lproc->cmd[2]]) + */
  /* 		      (lproc->reg[(int)lproc->cmd[3]]))]; */
  /*   } */
  /* if ((lproc->cmd[0] >> 4) & 0x03 == 1 && (lproc->cmd[0] >> 2) & 0x03 == 1) */
  /*   { */
  /*     if (lproc->cmd[2] > 16 && lproc->cmd[2] > 16) */
  /* 	{ */
  /* 	  lproc->pc += 1; */
  /* 	  return ; */
  /* 	} */
  /*     lproc->reg[(int)lproc->cmd[1]] = */
  /* 	vm->mem[(int)((lproc->reg[(int)lproc->cmd[2]]) + */
  /* 		      (lproc->reg[(int)lproc->cmd[3]]))]; */
  /*   } */
}
