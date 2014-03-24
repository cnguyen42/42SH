/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grebett <grebett@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/24 15:35:33 by grebett           #+#    #+#             */
/*   Updated: 2014/03/24 15:35:33 by grebett          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include <ft_signal.h>
# include <builtins.h>
# include <get_next_line.h>
# include <libft.h>
# include <dirent.h>
# include <fcntl.h>
# include <term.h>
# include <sys/ioctl.h>
# include <minishell3.h>

# define ENV_FILE "/tmp/42sh_env"
# define PA1 "PATH=/nfs/zfs-student-2/users/2013/jponcele/usr/local/bin:/usr/"
# define PA2 ":local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin"
# define TERM "TERM=xterm-256color"

# define TYPE_EXEC  {sh_ascii, sh_left, sh_right, sh_del, sh_suppr, sh_up,
# define TYPE_EXEC2 sh_down, sh_home, sh_end, sh_clear, sh_alt_up, sh_alt_down,
# define TYPE_EXEC3 sh_alt_right, sh_alt_left}
# define TYPE_SIZE 14

# define ST_C {'`', '\'', '\"', '(', ')', '{', '}'}
# define ST_C_VALUE {1, 2, 3, 4, 6, 5, 7}
# define ST_C_SIZE 7

# define STRINGS {"bquote ", "quote ", "dquote ", "subsh ", "cursh "}
# define STRINGS_SIZE 5

enum						e_state
{
	NO = 0, BQUOTE = 1, QUOTE = 2, DQUOTE = 3, SUBSH_I = 4, CURSH_I = 5,
	SUBSH_O = 6, CURSH_O = 7, TAB = 14, SHIFT = 15
};

# define OPE {"<<", ">>", "&&", "||", ";", "|", "<", ">"}
# define OPE_SIZE 8
# define LEVEL_MAX 2

# define TREE {0, 1, 2, -1, 3, 4}
# define TREE_EXEC {ft_semicolon, ft_pipe, ft_chevron, ft_cmd, ft_and, ft_or}
# define TREE_SIZE 6

# define SIGN {}
# define SIGN_EXE {}
# define SIGN_SIZE 0

# define SH_NOTFOUND "42sh: command not found: "
# define SH_PARSE "42sh: parse error near "
# define SH_DENIED "42sh: permission denied: "
# define SH_NOSUCH "42sh: no such file or directory: "

/*
**	flag = 0 : oper
**	flag = 1 : cmd 
**	flag = 2 : intput trunc
**	flag = 3 : heredoc
**	flag = 4 : output trunc
**	flag = 5 : output append
**	flag = 6 : NULL
*/

enum						e_type
{
	RETURN = -1, ASCII = 0, LEFT = 1, RIGHT = 2, DEL = 3, SUPPR = 4,
	UP = 5, DOWN = 6, HOME = 7, END = 8, CLEAR = 9, ALT_UP = 10,
	ALT_DOWN = 11, ALT_RIGHT = 12, ALT_LEFT = 13
};

typedef struct				s_node
{
	int						bin;
	int						flag;
	int						oper;
	char					**ctab;
	int						len;
	struct s_node			*dad;
	struct s_node			*left;
	struct s_node			*right;
}							t_node;

typedef struct				s_ope
{
	int						level;
	char					*ope;
}							t_ope;

typedef struct				s_dlst_cmd
{
	char					c;
	struct s_dlst_cmd		*next;
	struct s_dlst_cmd		*prev;
}							t_dlst_cmd;

typedef struct				s_cmd
{
	int						size;
	int						cursor;
	int						index;
	int						state;
	int						*state_bool;
	t_dlst_cmd				**adlst;
}							t_cmd;

typedef struct				s_dlst_histo
{
	t_cmd					*cmd;
	struct s_dlst_histo		*next;
	struct s_dlst_histo		*prev;
}							t_dlst_histo;

typedef struct				s_sh
{
	char					*pid;
	struct termios			term;
	t_dlst_histo			**histo;
	int						histo_size;
	int						histo_pos;
	t_cmd					*cmd;
	t_cmd					*cmd_save;
	int						*stop;
	int						ft_stdin;
	int						ft_stdout;
	char					**tokens;
	t_ope					*ope_ord;
	t_node					*root;
}							t_sh;

/*
**	Environ.c
*/

void			create_env(char **env);
char			**default_env(void);
char			**get_env(void);
char			**add_builtin_pid(char **env);

/*
**	setters.c
*/

char			**setctab(char *str);
t_ope			*set_ope_ord(void);
int				set_flag(t_node *node, t_ope *ope, int i);
int				set_oper(t_node *cur);

/*
**	setters_term.c
*/

void			set_key(char key[6], int fd);
int				set_type(t_sh *sh, char key[6], int *stop);

/*
**	error.c
*/

void			error(char *str_error);

/*
**	get_sh.c
*/

t_sh			*get_sh(int *stop);

/*
**	signal.c
*/

void			set_signal(void);
void			ft_signal(int sign);

/*
**	terminal.c
*/

void			set_terminal(t_sh *sh);

/*
**	print_minipromt.c
*/

void			print_miniprompt(t_cmd *cmd);

/*
**	get_next_cmd.c
*/

int				get_next_cmd(t_sh *sh, int fd, char **cmd);

/*
**	automate.c
*/

void			check_state(t_cmd *cmd);

/*
**	type_exec.c
*/

void			sh_ascii(t_sh *sh, char key[6]);
void			sh_left(t_sh *sh, char key[6]);
void			sh_right(t_sh *sh, char key[6]);
void			sh_del(t_sh *sh, char key[6]);
void			sh_suppr(t_sh *sh, char key[6]);

void			sh_up(t_sh *sh, char key[6]);
void			sh_down(t_sh *sh, char key[6]);
void			sh_home(t_sh *sh, char key[6]);
void			sh_end(t_sh *sh, char key[6]);

void			sh_alt_up(t_sh *sh, char key[6]);
void			sh_alt_down(t_sh *sh, char key[6]);
void			sh_alt_right(t_sh *sh, char key[6]);
void			sh_alt_left(t_sh *sh, char key[6]);
void			sh_clear(t_sh *sh, char key[6]);

/*
**	tput_putchar.c
*/

int				tputs_putchar(int c);

/*
**	dlst
*/

void			ft_dlst_cmd_addtopos(t_cmd *cmd, t_dlst_cmd *new, int pos);
void			ft_dlst_cmd_del(t_cmd *cmd);
void			ft_dlst_cmd_delone(t_dlst_cmd *cmd);
void			ft_dlst_cmd_delpos(t_cmd *cmd, int pos);
t_dlst_cmd		*ft_dlst_cmd_new(char c);
char			*ft_dlst_cmd_tostr(t_cmd *cmd);
t_cmd			*ft_cmd_dup(t_cmd *cmd);

void			ft_dlst_histo_addtopos(t_sh *sh, t_dlst_histo *new, int pos);
void			ft_dlst_histo_delpos(t_sh *sh, int pos);
t_dlst_histo	*ft_dlst_histo_new(t_cmd *cmd);

/*
**	prompt.c
*/

void			printprompt(t_usent **us);

/*
**	ft_env_annexe_sh.c
*/

char			*ft_getenv(const char *);
int				ft_putenv(char *name, char *value);
void			ft_printenv(void);

/*
**	start_sh.c
*/

void			start_sh(t_sh *sh);

/*
**	splittoken.c
*/

char			**splittoken(char **tokens, char *cmd, char **ope);

/*
**	tokentotree.c
*/

t_node			*token_to_tree(char **tokens, t_ope *ope);

/*
**	check_tree.c
*/

char			**check_gnl(char **tokens);
void			check_fd(t_node *cur);
void			check_case(t_node *cur);

/*
**	new_node.c
*/

t_node			*new_node(char **content, t_node *dad);

/*
**	exectree.c
*/

int				exec_node(t_sh *sh, t_node *cur);

/*
**	tree.c
*/

int				ft_semicolon(t_sh *sh, t_node *cur, t_node *l, t_node *r);
int				ft_seminode(t_sh *sh, t_node *node);
int				ft_pipe(t_sh *sh, t_node *cur, t_node *left, t_node *right);
int				ft_chevron(t_sh *sh, t_node *cur, t_node *left, t_node *right);
int				ft_cmd(t_sh *sh, t_node *cur, t_node *left, t_node *right);

int				ft_and(t_sh *sh, t_node *cur, t_node *left, t_node *right);
int				ft_or(t_sh *sh, t_node *cur, t_node *left, t_node *right);

/*
**	Check_glob.c
*/

void			check_glob(char **ctab);

/*
**	check_cmd.c
*/

int				check_file(t_node *right);
char			*check_cmd(t_sh *sh, char *cmd);

/*
**	exec_cmd.c
*/

void			exec_cmd(t_sh *sh, char **ctab);

/*
**	cmd_split.c
*/

char			**cmd_split(char *str);

/*
**	struct.c
*/

t_sh			*init_sh(t_sh *sh, char **arg);
void			free_sh(t_sh *sh);

/*
**	Ft-sleep.c
*/

void			ft_sleep(int i);

#endif /* !SH_H */
