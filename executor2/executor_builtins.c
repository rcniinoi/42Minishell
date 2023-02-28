/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:50:12 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:50:14 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char **cmd)
{
	int	i;

	i = 0;
	if (ft_strncmpp(cmd[1], "-n", 2) == 0)
		i = 1;
	while (cmd[++i])
	{
		printf("%s", cmd[i]);
		if (cmd[i + 1] != NULL)
			printf(" ");
	}
	if (ft_strncmpp(cmd[1], "-n", 2) == 1)
		printf("\n");
}

static int	ft_cd2(t_pipe *p, t_data *data, int i)
{
	if (i != ft_strlen_c2d(data->env))
		chdir(&(data->env[i][5]));
	else
	{
		printf("%s%s\n", p->cmd[0], ERR_HNS);
		*(data->ex_s) = 1;
		return (1);
	}
	return (0);
}

void	ft_cd(t_pipe *p, t_data *data, t_cmd *cmd)
{
	int	i;

	if (data->count_cmd == 1 && ft_strlen_c2d(cmd->i_tab) == 0 && \
		ft_strlen_c2d(cmd->o_tab) == 0)
	{
		if (p->cmd[1] == NULL || p->cmd[1][0] == '\0' || p->cmd[1][0] == '~')
		{
			i = 0;
			while (ft_strncmpp(HOME, data->env[i], 5))
				i++;
			if (ft_cd2(p, data, i))
				return ;
		}
		else
		{
			if (chdir(p->cmd[1]) == -1)
			{
				printf("%s: %s%s\n", p->cmd[0], p->cmd[1], ERR_NFD);
				*(data->ex_s) = 1;
				return ;
			}
		}
		*(data->ex_s) = 0;
	}
}

int	ft_pwd(int mode)
{
	char	*pwd;

	if (mode == 1)
	{
		pwd = getcwd(NULL, 1000);
		printf("%s\n", pwd);
		free(pwd);
	}
	return (0);
}

int	ft_export(t_pipe *p, t_data *data, int mode)
{
	int	c_cmd;
	int	r;

	c_cmd = ft_strlen_c2d(p->cmd);
	if (c_cmd == 1)
	{
		if (mode == 1)
			ft_print_export(data->env);
		r = 0;
	}
	else
		r = ft_add_export(p, &data, mode);
	return (r);
}
