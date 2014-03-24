# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: grebett <grebett@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/03/24 15:20:55 by grebett           #+#    #+#              #
#    Updated: 2014/03/24 15:20:55 by grebett          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = builtins

DIRSRC = ./srcs/
DIROBJ = ./obj/

SRC = ft_envs_annexe_sh.c\
	  environ.c\
	  setters.c\
	  tputs_putchar.c
OBJ = $(SRC:.c=.o)
DIROBJS = $(addprefix $(DIROBJ), $(OBJ))

#			CD

CD_DIRSRC = ./cd_srcs/
CD_DIROBJ = ./cd_obj/

CD_SRC = main.c\
		 ft_cd_sh.c
CD_OBJ = $(CD_SRC:.c=.o)
CD_DIROBJS = $(addprefix $(CD_DIROBJ), $(CD_OBJ))

#			ENV

ENV_DIRSRC = ./env_srcs/
ENV_DIROBJ = ./env_obj/

ENV_SRC = main.c\
		  ft_env_sh.c
ENV_OBJ = $(ENV_SRC:.c=.o)
ENV_DIROBJS = $(addprefix $(ENV_DIROBJ), $(ENV_OBJ))

#			SETENV

SETENV_DIRSRC = ./setenv_srcs/
SETENV_DIROBJ = ./setenv_obj/

SETENV_SRC = main.c\
			 ft_setenv.c
SETENV_OBJ = $(SETENV_SRC:.c=.o)
SETENV_DIROBJS = $(addprefix $(SETENV_DIROBJ), $(SETENV_OBJ))

#			UNSETENV

UNSETENV_DIRSRC = ./unsetenv_srcs/
UNSETENV_DIROBJ = ./unsetenv_obj/

UNSETENV_SRC = main.c\
			   ft_unsetenv.c
UNSETENV_OBJ = $(UNSETENV_SRC:.c=.o)
UNSETENV_DIROBJS = $(addprefix $(UNSETENV_DIROBJ), $(UNSETENV_OBJ))

#			ECHO

ECHO_DIRSRC = ./echo_srcs/
ECHO_DIROBJ = ./echo_obj/

ECHO_SRC = main.c\
		   ft_echo.c
ECHO_OBJ = $(ECHO_SRC:.c=.o)
ECHO_DIROBJS = $(addprefix $(ECHO_DIROBJ), $(ECHO_OBJ))

#			HIST

HIST_DIRSRC = ./hist_srcs/
HIST_DIROBJ = ./hist_obj/

HIST_SRC = main.c
HIST_OBJ = $(HIST_SRC:.c=.o)
HIST_DIROBJS = $(addprefix $(HIST_DIROBJ), $(HIST_OBJ))

#			EXIT

EXIT_DIRSRC = ./exit_srcs/
EXIT_DIROBJ = ./exit_obj/

EXIT_SRC = main.c
EXIT_OBJ = $(EXIT_SRC:.c=.o)
EXIT_DIROBJS = $(addprefix $(EXIT_DIROBJ), $(EXIT_OBJ))

LFT = -L ../libft/ -lft
LTERM = -L /usr/lib -ltermcap

CC = clang
CFLAGS = -Wall -Werror -Wextra -O3 -g

HEAD = -I ../includes -I ../libft/includes/

all: $(NAME)

$(NAME): gal cd echo exit env setenv unsetenv hist

gal: $(DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'

$(DIROBJ)%.o: $(DIRSRC)%.c
	@mkdir -p $(DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

cd: $(CD_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(CD_DIROBJ)%.o: $(CD_DIRSRC)%.c
	@mkdir -p $(CD_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

echo: $(ECHO_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(ECHO_DIROBJ)%.o: $(ECHO_DIRSRC)%.c
	@mkdir -p $(ECHO_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

exit: $(EXIT_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT) $(LTERM)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(EXIT_DIROBJ)%.o: $(EXIT_DIRSRC)%.c
	@mkdir -p $(EXIT_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

env: $(ENV_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(ENV_DIROBJ)%.o: $(ENV_DIRSRC)%.c
	@mkdir -p $(ENV_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

setenv: $(SETENV_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(SETENV_DIROBJ)%.o: $(SETENV_DIRSRC)%.c
	@mkdir -p $(SETENV_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

unsetenv: $(UNSETENV_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(UNSETENV_DIROBJ)%.o: $(UNSETENV_DIRSRC)%.c
	@mkdir -p $(UNSETENV_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

hist: $(HIST_DIROBJS)
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$@'
	@$(CC) $(CFLAGS) -o $@ $^ $(DIROBJS) $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$@'

$(HIST_DIROBJ)%.o: $(HIST_DIRSRC)%.c
	@mkdir -p $(HIST_DIROBJ)
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

clean:
	@rm -rf $(CD_DIROBJ) $(EXIT_DIROBJ) $(ECHO_DIROBJ) $(HIST_DIROBJ)
	@rm -rf $(ENV_DIROBJ) $(SETENV_DIROBJ) $(UNSETENV_DIROBJ) $(DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ../libft

fclean: clean
	@$(RM) $(RFLAGS) cd echo exit env setenv unsetenv hist
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ../libft

re : fclean all

.PHONY: all clean fclean re cd echo exit env setenv unsetenv hist
