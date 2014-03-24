# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcojan <dcojan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/24 15:47:24 by dcojan            #+#    #+#              #
#    Updated: 2014/03/24 15:47:24 by dcojan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 42sh

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = main.c\
	  environ.c\
	  signal.c\
	  setters.c\
	  error.c\
	  signal.c\
	  print_miniprompt.c\
	  tputs_putchar.c\
	  automate.c\
	  get_sh.c\
	  prompt.c\
	  start_sh.c\
	  ft_envs_annexe_sh.c\
	  splittoken.c\
	  tokentotree.c\
	  new_node.c\
	  exectree.c\
	  check_tree.c\
	  check_glob.c\
	  tree.c\
	  tree2.c\
	  check_cmd.c\
	  ft_sleep.c\
	  terminal.c

SRC +=	ft_dlst_cmd_addtopos.c\
		ft_dlst_cmd_del.c\
		ft_dlst_cmd_delone.c\
		ft_dlst_cmd_delpos.c\
		ft_dlst_cmd_new.c\
		ft_dlst_cmd_tostr.c\
		ft_cmd_dup.c

SRC +=	ft_dlst_histo_addtopos.c\
		ft_dlst_histo_delpos.c\
		ft_dlst_histo_new.c

SRC +=  ft_minishell3.c\
		user_entry_init.c\
		user_entry_init2.c\
		cursor_move.c\
		cursor_move2.c\
		sh3_user_entry.c\
		sh3_user_entry_display.c\
		sh3_user_entry_process_key.c\
		sh3_user_entry_process_key2.c\
		sh3_user_entry_edition.c\
		sh3_user_entry_history.c\
		sh3_user_entry_get_key.c\
		sh3_user_entry_state_flag.c\
		sh3_termios.c\
		sh3_prompt.c\
		sh3_error.c\
		sh_tputchar.c\
		sh3_quit.c

OBJ = $(SRC:.c=.o)

DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

LFT = -L ./libft/ -lft
LTERM = -L /usr/lib -ltermcap

CC = clang
CFLAGS = -Wall -Werror -Wextra -g

HEAD = -I ./includes -I ./libft/includes/

all: $(NAME)

$(NAME): $(DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) -C ./libft/
	@$(MAKE) -C ./builtins/
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT) $(LTERM)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$(NAME)'

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./builtins

fclean: clean
	@$(RM) $(RFLAGS) $(NAME)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./builtins

re : fclean all

.PHONY: all clean fclean re
