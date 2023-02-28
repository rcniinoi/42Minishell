/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:23:17 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:23:19 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_chk_path(t_pipe *pipe, t_data *data)
{
	int		i;
	char	*chk;

	i = -1;
	while (data->path != NULL && data->path[++i] 
		&& pipe->cmd[0] != NULL)
	{
		chk = ft_strjoinn("", pipe->cmd[0]);
		if (access(chk, F_OK | X_OK) == 0)
			return (chk);
		free(chk);
		chk = ft_strjoinn(data->path[i], pipe->cmd[0]);
		if (access(chk, F_OK | X_OK) == 0)
			return (chk);
		free(chk);
	}
	return (NULL);
}

static int	ft_chk_infile(t_pipe *p, t_cmd *cmd)
{
	int			i;
	static int	tmp;

	i = -1;
	tmp = 0;
	while (cmd->i_tab[++i])
	{
		if (cmd->sign_i[i] == 1)
			p->infile = open(cmd->i_tab[i], O_RDWR);
		else if (cmd->sign_i[i] == 2)
			ft_here_doc(p, cmd, i, tmp++);
		if (cmd->i_tab[i + 1] != NULL)
			close(p->infile);
	}
	if (i != 0)
		return (1);
	return (0);
}

static int	ft_chk_outfile(t_pipe *pipe, t_cmd *cmd)
{
	int	i;

	i = -1;
	while (cmd->o_tab[++i])
	{
		if (cmd->sign_o[i] == 1)
		{
			pipe->outfile = open(cmd->o_tab[i], \
				O_RDWR | O_TRUNC | O_CREAT, 0644);
		}
		else if (cmd->sign_o[i] == 2)
		{
			pipe->outfile = open(cmd->o_tab[i], \
				O_RDWR | O_APPEND | O_CREAT, 0644);
		}
		if (cmd->o_tab[i + 1] != NULL)
			close(pipe->outfile);
	}
	if (i != 0)
		return (1);
	return (0);
}

static void	ft_set_pipe(t_pipe *p, t_data *data, t_cmd *cmd, int loop)
{
	if (loop == 0 && cmd->i_tab[0] == NULL && cmd->sign_i[0] == 0)
		dup2(data->ori_fd[0], 0);
	else if (ft_chk_infile(p, cmd))
		dup2(p->infile, 0);
	else
		dup2(data->fd_pipe[loop - 1][0], 0);
	if (loop == data->count_cmd - 1 && cmd->o_tab[0] == NULL \
		&& cmd->sign_o[0] == 0)
		dup2(data->ori_fd[1], 1);
	else if (ft_chk_outfile(p, cmd))
		dup2(p->outfile, 1);
	else
		dup2(data->fd_pipe[loop][1], 1);
}

void	ft_fork(t_cmd *cmd, t_data *data, int loop)
{
	t_pipe	p;
	p.cmd = cmd->cmd;
	p.path = ft_chk_path(&p, data);
	data->child_pid[loop] = fork();
	if (data->child_pid[loop] == 0)
	{
		ft_set_pipe(&p, data, cmd, loop);
		ft_close(data, loop);
		if (p.cmd[0] != NULL && ft_chk_builtins(p.cmd[0]) == 0)
			ft_chk_child(&p, data);
		else
			execve(p.path, p.cmd, data->env);
		if (p.cmd[0] != NULL && ft_chk_builtins(p.cmd[0]))
			printf("%s%s\n", p.cmd[0], ERR_CMM);
		exit (127);
	}
	else if (data->child_pid[loop] > 0)
	{
		ft_chk_parent(&p, data, cmd);
		ft_close_parent(data, loop);
		if (p.cmd[0] != NULL && p.path == NULL && ft_chk_builtins(p.cmd[0]))
			*(data->ex_s) = 127;
		else if (p.cmd[0] != NULL &&(p.path != NULL || ft_chk_builtins(p.cmd[0]) == 0) \
			&& ft_strncmpp(p.cmd[0], "$?", 2))
			*(data->ex_s) = 0;
	}
	ft_free_pipe(&p);
}
