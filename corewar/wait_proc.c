#include "lib.h"
#include "vm.h"
#include "couleur.h"
#include "instructions/instruction.h"

/*
** retourn le temp de de cycle de l' instruction.
*/
int	wait_proc(int cmd)
{
  if (cmd >= 0 && cmd <= REG_NUMBER)
    return (cmd_tab[cmd].cycle);
  return (1);
}
