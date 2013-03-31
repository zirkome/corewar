/*
** instruction.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Tue Jan 29 07:29:27 2013 guillaume fillon
** Last update Sun Mar 31 03:26:47 2013 guillaume fillon
*/

#include "vm.h"
#include "lib.h"
#include "instruction.h"

t_cmd	cmd_tab[] =
  {
    {0x01, 10,   op_live,  "live"},
    {0x02, 5,    op_ld,    "ld"},
    {0x03, 5,    op_st,    "st"},
    {0x04, 10,   op_add,   "add"},
    {0x05, 10,   op_sub,   "sub"},
    {0x06, 6,    op_and,   "and"},
    {0x07, 6,    op_or,    "or"},
    {0x08, 6,    op_xor,   "xor"},
    {0x09, 20,   op_zjmp,  "zjmp"},
    {0x0A, 25,   op_ldi,   "ldi"},
    {0x0B, 25,   op_sti,   "sti"},
    {0x0C, 800,  op_fork,  "fork"},
    {0x0D, 10,   op_lld,   "lld"},
    {0x0E, 50,   op_lldi,  "lldi"},
    {0x0F, 1000, op_lfork, "lfork"},
    {0x10, 2,    op_aff,   "aff"},
    {0x0,  0,    NULL,     NULL}
  };
