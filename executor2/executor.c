/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:51:04 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:51:06 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_serch_path(t_data *data, char **env)
{
	int	i;
	int	env_l;

	i = 0;
	env_l = ft_strlen_c2d(env);
	while (env[i] && ft_strncmpp(PATH, env[i], 5))
		i++;
	if (env_l != i)
		data->path = ft_splitt(&env[i][5], ':');
	else
		data->path = NULL;
	data->env = env;
}

static void	ft_set_ori_fd(t_data *data)
{
	data->ori_fd[0] = dup(STDIN_FILENO);
	data->ori_fd[1] = dup(STDOUT_FILENO);
}

static int	ft_count_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		count;

	tmp = cmd;
	count = 0;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

static void	ft_init_pipe(t_data *data)
{
	int	i;

	data->fd_pipe = malloc(sizeof(int *) * (data->count_cmd - 1));
	if (data->fd_pipe == NULL)
		return ;
	i = -1;
	while (++i < data->count_cmd - 1)
	{
		data->fd_pipe[i] = malloc(sizeof(int) * 2);
		if (data->fd_pipe[i] == NULL)
			return ;
	}
	i = -1;
	while (++i < data->count_cmd - 1)
		pipe(data->fd_pipe[i]);
}

void	ft_executor(t_cmd *cmd, t_data *data, int	*ex_s)
{
	int		i;

	if (ft_chk_io_file(cmd, ex_s))
		return ;
	ft_serch_path(data, data->env);
	data->ex_s = ex_s;
	i = -1;
	while (data->path != NULL && data->path[++i])
		data->path[i] = ft_strjoin_free(data->path[i], "/");
	ft_set_ori_fd(data);
	data->count_cmd = ft_count_cmd(cmd);
	data->child_pid = malloc(sizeof(int) * data->count_cmd);
	if (data->count_cmd > 1)
		ft_init_pipe(data);
	i = -1;
	while (cmd)
	{
		ft_fork(cmd, data, ++i);
		cmd = cmd->next;
	}
	i = -1;
	while (++i < data->count_cmd)
		waitpid(data->child_pid[i], NULL, 0);
	ft_free_data(data, "noexit");
}
