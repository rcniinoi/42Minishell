/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:11:47 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/17 03:18:20 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <sys/ioctl.h>
# include <errno.h>
# include <term.h>
# include "struct.h"
# include "g_n_l/g_n_l.h"
# include "libft/libft.h"
# include "executor2/executor.h"

# define SINGLE 1
# define DOUBLE 2
# define RE_INPUT 4
# define RE_OUTPUT 5
# define PROMPT "minishell start here > "
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define BLUE "\e[1;34m"
# define CYAN "\e[1;36m"
# define YELLOW "\e[1;33m"
# define CLEAR "\033[0m"

// shdec
char	*ft_promptstart(int mode);
void	ft_avjoin(char *av, int mode, t_shell *shell);
void	ft_promptpare(int ac, char **av, t_shell *shell);
// sub_main
int		ft_submain(t_shell *shell, char **env);
// lexor
int		ft_lexmain(t_shell *shell, int start, int len);
// lexor_utils
int		ft_isspace(int c);
int		ft_isarrowpipe(int c);
int		ft_isquote(int c);
int		ft_issymbol(int c, char sym);
void	ft_nextlex_init(t_intvar *inv, int start, int *e, t_lex *tall);
// error checking
int		ft_chkandgo(t_lex *lex);
int		ft_isclosequote(t_lex *lex);
int		ft_triplearrow(t_lex *lex);
int		ft_triplepipe(t_lex *lex);
// parser
int		ft_parser(t_shell *shell);
int		ft_choosecount(char	**lex, char a);
int		ft_strstrlen(char **str);
// parser_utils
t_par	*ft_parini(t_shell *shell, int i);
void	ft_parinsert(t_par *par, t_cmd *tcmd, char **str);
t_cmd	*ft_cmdmaker(t_shell *shell);
t_cmd	*ft_tcmdini(t_shell *shell, int i);
// parser_utils2
void	ft_instcmdtopar(t_shell *shell, t_par *par, int ststlen, int j);
void	ft_parinsert2(char **str, t_parinsert *tmp, t_par *par, t_cmd *tcmd);
void	ft_parinsert_init(t_parinsert *tmp, char **str);
// expander c
char	*ft_envcompare(char *str, char **env, int *exit_s);
char	*ft_putpath(char **cmd, char **envar, char **fullvar, int i);
// expander_utils
char	*ft_envargetter(char **cmd, int i);
int		ft_expander(t_shell *shell, char **env, int *exit_s);
// expander_utils2
int		ft_exptostr(t_shell *shell);
// expanderutil
t_exp	*ft_expini(t_shell *shell);
t_exp	*ft_expmaker(t_shell *shell);
// free
void	ft_free2(char ***dptr);
void	ft_freeexp(t_shell	*shell);
void	ft_freepar(t_shell *shell);
void	ft_freetcmd(t_shell *shell);
t_cmd	*ft_finini(t_shell *shell);
t_cmd	*ft_finmaker(t_shell *shell);
// signal
void	ft_signals(void);
void	ft_handler(int signo, siginfo_t *s, void *old);

#endif
