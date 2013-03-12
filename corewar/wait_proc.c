/*
** wait_proc.c for wait_proc in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi
** Login   <remi@epitech.net>
**
** Started on  Tue Mar 12 13:02:47 2013 remi
** Last update Tue Mar 12 13:05:00 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"
#include "instructions/instruction.h"

int	wait_proc(int cmd)
{
  if (cmd >= 0 && cmd <= 16)
    return (cmd_tab[cmd].cycle);
  return (1);
}
