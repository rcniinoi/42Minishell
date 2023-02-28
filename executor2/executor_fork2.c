/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_fork2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:17:16 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:17:17 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_close(t_data *data, int loop)
{
	while (loop < data->count_cmd - 1)
	{
		close(data->fd_pipe[loop][0]);
		close(data->fd_pipe[loop][1]);
		loop++;
	}
}

void	ft_close_parent(t_data *data, int loop)
{
	if (data->count_cmd != 1)
	{
		if (loop == 0)
			close(data->fd_pipe[loop][1]);
		else if (loop == data->count_cmd - 1)
			close(data->fd_pipe[loop - 1][0]);
		else
		{
			close(data->fd_pipe[loop - 1][0]);
			close(data->fd_pipe[loop][1]);
		}
	}
}

void	ft_here_doc(t_pipe *p, t_cmd *cmd, int idx, int tmp)
{
	char	name[30];
	char	*str;
	int		fd;

	ft_strlcpyy(name, "/tmp/tmp", 8);
	str = ft_itoaa(tmp);
	ft_strlcatt(name, str, 100);
	free(str);
	fd = open(name, O_RDWR | O_TRUNC | O_CREAT, 0644);
	while (1)
	{
		write(1, "heredoc> ", 9);
		str = get_next_line(0);
		if (ft_strcmpp(str, cmd->i_tab[idx], ft_strlenn(str)))
			break ;
		write(fd, str, ft_strlenn(str));
		free(str);
	}
	free(str);
	close(fd);
	p->infile = open(name, O_RDWR);
}

void	ft_chk_child(t_pipe *p, t_data *data)
{
	if (ft_strncmpp(p->cmd[0], "echo", 4) == 0)
	{
		if (p->cmd[1] == NULL)
			write(1, "\n", 1);
		else
			ft_echo(p->cmd);
	}
	else if (ft_strncmpp(p->cmd[0], "pwd", 3) == 0)
		ft_pwd(PRT);
	else if (ft_strncmpp(p->cmd[0], "export", 6) == 0)
		ft_export(p, data, PRT);
	else if (ft_strncmpp(p->cmd[0], "unset", 5) == 0)
		ft_unset(p, data, PRT);
	else if (ft_strncmpp(p->cmd[0], "env", 3) == 0)
		ft_env(data->env);
	if (ft_strncmpp(p->cmd[0], "pwd", 3) == 0 || \
		ft_strncmpp(p->cmd[0], "export", 6) == 0 || \
		ft_strncmpp(p->cmd[0], "unset", 5) == 0 || \
		ft_strncmpp(p->cmd[0], "env", 3) == 0)
		exit(0);
}

void	ft_chk_parent(t_pipe *p, t_data *data, t_cmd *cmd)
{
	if (p->cmd[0] != NULL)
	{
		if (ft_strncmpp(p->cmd[0], "cd", 2) == 0)
			ft_cd(p, data, cmd);
		else if (ft_strncmpp(p->cmd[0], "pwd", 3) == 0)
			*(data->ex_s) = ft_pwd(NPRT);
		else if (ft_strncmpp(p->cmd[0], "export", 6) == 0)
			*(data->ex_s) = ft_export(p, data, NPRT);
		else if (ft_strncmpp(p->cmd[0], "unset", 5) == 0)
			*(data->ex_s) = ft_unset(p, data, NPRT);
		else if (ft_strncmpp(p->cmd[0], "exit", 4) == 0)
			ft_exit(p, data);
		else if (ft_strncmpp(p->cmd[0], "$?", 2) == 0)
			printf("%d: command not found\n", *(data->ex_s));
	}
}
