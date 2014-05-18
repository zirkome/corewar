#include "vm.h"

/*
** met le carry à 0 ou a 1 suivant la valeur passé.
** si val == 0 alors carry = 1;
*/
void	set_carry(t_proc **lproc, int val)
{
  if (val == 0)
    {
      my_putstr("\n");
      my_putstr(F_ROUGE);
      my_putstr("carry = 1");
      my_putstr(REZ);
      (*lproc)->carry = 1;
    }
  else
    (*lproc)->carry = 0;
}
