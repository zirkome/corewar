/*
** my_memset.c for memset in /home/remi/Projet/save_projet/corewar/corewar
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Sun Mar 31 18:50:35 2013 remi robert
** Last update Sun Mar 31 18:51:02 2013 remi robert
*/

#include "vm.h"

void	*my_memset(char *tab, int value, int size)
{
  int	indice;

  indice = 0;
  while (tab && indice < size)
    {
      tab[indice] = value;
      indice = indice + 1;
    }
  return (tab);
}
