/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:30:13 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/18 15:25:26 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# define PATH "PATH="
# define PWD "PWD="
# define OLDPWD "OLDPWD="
# define HOME "HOME="
# define PRT 1
# define NPRT 0

# define ERR_EXPORT ": not a valid identifier"
# define ERR_CMM ": command not found"
# define ERR_EXIT ": too many arguments"
# define ERR_EXIT_N ": numeric argument required"
# define ERR_NFD ": No such file or directory"
# define ERR_HNS ": HOME not set"

typedef struct s_pipe
{
	char	**cmd;
	char	*path;
	int		infile;
	int		outfile;
}	t_pipe;

typedef struct s_data
{
	char	**path;
	char	**env;
	int		ori_fd[2];
	int		**fd_pipe;
	int		count_cmd;
	int		*child_pid;
	int		*ex_s;
}	t_data;

// executor
void	ft_executor(t_cmd *cmd, t_data *data, int	*ex_s);
// executor2
int		ft_chk_io_file(t_cmd *cmd, int *ex_s);
// executor_fork
void	ft_fork(t_cmd *cmd, t_data *data, int loop);
// executor_fork2
void	ft_close(t_data *data, int loop);
void	ft_close_parent(t_data *data, int loop);
void	ft_here_doc(t_pipe *p, t_cmd *cmd, int idx, int tmp);
void	ft_chk_child(t_pipe *p, t_data *data);
void	ft_chk_parent(t_pipe *p, t_data *data, t_cmd *cmd);
// executor_fork3
int		ft_chk_builtins(char *cmd);
// executor_builtins
void	ft_echo(char **cmd);
void	ft_cd(t_pipe *p, t_data *data, t_cmd *cmd);
int		ft_pwd(int mode);
int		ft_export(t_pipe *p, t_data *data, int mode);
// executor_builtins2
void	ft_print_export(char **env);
int		ft_add_export(t_pipe *p, t_data **data, int mode);
// executor_builtins3
int		ft_count_add(char **cmd, char **env);
int		ft_chk_dup(char *s, char **env);
void	ft_insert_export(int *i, int j, t_pipe *p, char **n_env);
int		ft_unset(t_pipe *p, t_data *data, int mode);
// executor_builtins4
void	ft_env(char **env);
void	ft_exit(t_pipe *p, t_data *data);
int		ft_unset2(t_pipe *p, t_data *data, int mode, int *c_env);
// executor_builtins5
int		ft_add_export2(int *i, int mode, t_pipe *p, char **n_env);
// utils
int		ft_strlenn(char *s);
int		ft_strlen_c2d(char **s);
void	*ft_memcpyy(void *dst, void *src, int n);
char	*ft_strdupp(char *s1);
int		ft_strncmpp(char *s1, char *s2, int n);
// utils2
char	**ft_splitt(char *s, char c);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strjoinn(char *s1, char *s2);
// utils3
int		ft_strlen_i(int *s);
void	ft_strlcpyy(char *dst, char *src, int size);
char	*ft_itoaa(int n);
void	ft_strlcatt(char *dst, char *src, int size);
// utils4
int		ft_strcmpp(char *s1, char *s2, int size);
int		ft_strlen_2(char *s);
// free
void	ft_free_c2d(char **s);
void	ft_free_i2d(int	**s, int size);
void	ft_free_data(t_data *data, char *s);
void	ft_free_pipe(t_pipe *pipe);

int	ft_atoi(const char *str);
int	ft_isdigit(int c);

#endif
