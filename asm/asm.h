/*
** main.h for main.c in /home/bridou_n//putchar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Thu Jan 17 16:25:45 2013 nicolas bridoux
** Last update Thu Mar 14 11:11:49 2013 nicolas bridoux
*/

#ifndef ASM_H_
# define ASM_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "op.h"

# define READ		4096
# define LIVE		1
# define LD		2
# define ST		3
# define ADD		4
# define SUB		5
# define AND		6
# define OR		7
# define XOR		8
# define ZJMP		9
# define LDI		10
# define STI		11
# define FORK		12
# define LLD		13
# define LLDI		14
# define LFORK		15
# define AFF		16
# define GREEN		"\033[00;32m"
# define GREEN_BOLD	"\033[01;32m"
# define CYAN		"\033[00;36m"
# define CYAN_BOLD	"\033[01;36m"
# define BLUE		"\033[00;34m"
# define BLUE_BOLD	"\033[01;34m"
# define YELLOW		"\033[00;33m"
# define YELLOW_BOLD	"\033[01;33m"
# define RED		"\033[00;31m"
# define RED_BOLD	"\033[01;31m"
# define MAGENTA	"\033[00;35m"
# define INIT		"\033[00;0m"

typedef struct s_list t_list;
struct	s_list
{
  char		*name;
  int		pos;
  int		pos_label;
  t_list	*next;
};

typedef	struct s_cmd
{
  int	i;
  int	nb_cmd;
  int	size_cmd;
  int	*k;
}	t_cmd;

typedef struct s_compile t_compile;
struct s_compile
{
  int		i;
  int		k;
  char		*label;
  t_list	*call_label;
  t_list	*declare_label;
};

/* my_putchar.c */
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_error(char *str, int quit);
int	my_strlen(char *str);
void	my_put_nbr(int nb);

/* my_string.c */
void	my_strcat(char *s1, char *s2);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
void	my_strcpy(char *dest, char *src);
char	*my_strdup(char *str);

/* read_fd.c */
char	*read_fd(const int fd);
int	my_getnbr(char *str);
void	shift_string(char *str, int i);

/* main.c */
void	load(char *name);
void	check_file(char *new_name);

/* my_parsing.c */
void	my_parsing(char *file, char *name);
void	replace_space_ignore_comment(char *file);
void	remove_space_and_tab(char *file);
void	remove_comment(char *file);
void	remove_spaces_added(char *f);

/* make_header.c */
void	make_header(char *file, char *name);
int	make_comment_and_size(char *comment, char *file, char *champ_name);
char	*find_name(char *file);
char	*find_comment(char *file);

/* fill_name_and_comment.c */
void	fill_comment(char *comment, header_t *header);
void	fill_name_champ(char *name, header_t *header);
void	display_name_and_comment(header_t *header);

/* make_instruction_tab.c */
void	make_instruction_tab(char *file, char *name, header_t *header);
char	**fill_instruction_tab(char *file, int i, int k, int j);
int	nb_line(char *file);
void	remove_comment_and_name(char *file);

/* check_command_label.c */
int	command_exist(char *cmd);
char	*is_label(char *cmd, t_list **declare_label, int pos);
char	*find_name_final(char *name);
int	in_label_chars(char c, char *label_chars);
int	check_label_chars(t_list **, t_list **, char *);

/* make_compile.c */
void	make_compile(char *name, header_t *header, char **tab);
void	final_name(char *name, char *file_cor, int k, header_t *header);
void	is_label_null(char **tab, char *label);
int	compile_existing_cmd(char **tab, char **file_cor, t_compile *p);
int	compile_cmd_and_label(t_compile *p, char **tab, char *file_cor);

/* compilation_errors.c */
void	successfull(t_compile *p, char *name, char *file_cor, header_t *header);
void	error_unknow(int, char **, t_list *, t_list *);
void	error_param(int, char **, t_list *, t_list *);
char	*no_param_instruct(int nb_cmd, char *file_cor, int *k, char *cmd);
int	wrong_label_name(void);

/* my_list.c */
void	my_put_in_list(t_list **list, char *name, int pos, int pos_label);
void	my_show_list(t_list *list);

/* my_free.c */
void	my_free_list(t_list *list);
void	my_free_tab(char **tab);

/* check_instruct.c */
int	check_params(char *cmd, int nb_cmd);
int	check_ret(int ret);
int	check_nb_p(char *cmd, int nb_cmd);
int	check_param_type(char *cmd, int nb_cmd);
int	check_params_type(int i, char *cmd);

/* write_commands.c */
char	*write_command(char *file_cor, int *k, t_list **call_label, char *cmd);
char	arg_type(char *cmd);
char	*write_param(char *cmd, t_list **call_label, char *file_cor, int *k);
void	fill_call_label(t_list **, char *, int, int);
char	*my_write_octets(char *file_cor, int size, int param, int *k);

/* replace_label.c */
char	*replace_label(char *, t_list **, t_list **);
char	*error_unknow_label(char *, t_list **, t_list **, char *);
int	error_multiple_label(t_list **, t_list **, char *, char *);
int	check_multi_labels(t_list **, t_list **, char *);

/* cmd_pointer_tab.c */
char	*cmd_pointer_tab(char *, char *, t_cmd *, t_list **);

/* instruct_ld_lld.c */
char	*my_ld_lld(char *, char *, t_cmd *, t_list **);

/* instruct_add_sub.c */
char	*my_add_sub(char *, char *, t_cmd *, t_list **);

/* instruct_and_or_xor.c */
char	*my_and_or_xor(char *, char *, t_cmd *, t_list **);
char	*check_and_or_xor_param(char *, char *, t_cmd *, t_list **);

/* instruct_zjmp_live.c */
char	*my_zjmp(char *, char *, t_cmd *, t_list **);
char	*my_live(char *, char *, t_cmd *, t_list **);
char	*my_aff(char *, char *, t_cmd *, t_list **);

/* instruct_ldi_lldi.c */
char	*my_ldi_lldi(char *, char *, t_cmd *, t_list **);
char	*check_ldi_and_lldi_param(char *, char *, t_cmd *, t_list **);

/* instruct_fork_lfork.c */
char	*my_fork_lfork(char *, char *, t_cmd *, t_list **);

/* instruct_sti_st.c */
char	*my_sti(char *, char *, t_cmd *, t_list **);
char	*check_my_sti_param(char *, char *, t_cmd *, t_list **);
char	*my_st(char *, char *, t_cmd *, t_list **);

/* change_endian.c */
void	change_endian(header_t *header);

#endif /* ASM_H_ */
