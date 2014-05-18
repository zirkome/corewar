#include "asm.h"

/*
** Cette fonction remplit la partie commentaire du header avec le commentaire
** passé en param
*/

void	fill_comment(char *comment, header_t *header)
{
  int	i;

  i = -1;
  while (comment[++i] && i < COMMENT_LENGTH)
    header->comment[i] = comment[i];
  --i;
  while (++i <= COMMENT_LENGTH)
    header->comment[i] = 0x00;
  free(comment);
}

/*
** idem mais pour la partie nom
*/

void	fill_name_champ(char *name, header_t *header)
{
  int	i;

  i = -1;
  while (name[++i] && i < PROG_NAME_LENGTH)
    header->prog_name[i] = name[i];
  --i;
  while (++i <= PROG_NAME_LENGTH + 1)
    header->prog_name[i] = 0x00;
  free(name);
}

/*
** Affiche le nom + commentaire après la compilation
** A faire avec la structure header_t maintenant !
*/

void	display_name_and_comment(header_t *header)
{
  my_putstr(YELLOW);
  my_putstr("[Name] => ");
  my_putstr(INIT);
  my_putstr(header->prog_name);
  my_putchar('\n');
  my_putstr(MAGENTA);
  my_putstr("[Comment] => ");
  my_putstr(INIT);
  my_putstr(header->comment);
  my_putchar('\n');
}
