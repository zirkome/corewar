#include "asm.h"

/*
** Tableau de pointeur avec les 17 instructions différentes
*/

char	*cmd_pointer_tab(char *file_cor, char *cmd, t_cmd *cmd_oct,
			 t_list **call_label)
{
  char	*(*my_cmd[17])(char *, char *, t_cmd *, t_list **);

  my_cmd[LIVE] = &my_live;
  my_cmd[LD] = &my_ld_lld;
  my_cmd[ST] = &my_st;
  my_cmd[ADD] = &my_add_sub;
  my_cmd[SUB] = &my_add_sub;
  my_cmd[AND] = &my_and_or_xor;
  my_cmd[OR] = &my_and_or_xor;
  my_cmd[XOR] = &my_and_or_xor;
  my_cmd[ZJMP] = &my_zjmp;
  my_cmd[LDI] = &my_ldi_lldi;
  my_cmd[STI] = &my_sti;
  my_cmd[FORK] = &my_fork_lfork;
  my_cmd[LLD] = &my_ld_lld;
  my_cmd[LLDI] = &my_ldi_lldi;
  my_cmd[LFORK] = &my_fork_lfork;
  my_cmd[AFF] = my_aff;
  if (cmd_oct->nb_cmd <= AFF && cmd_oct->nb_cmd)
    return (my_cmd[cmd_oct->nb_cmd](file_cor, cmd, cmd_oct, call_label));
  return (file_cor);
}
