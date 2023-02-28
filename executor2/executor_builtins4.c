/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins4.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:24:05 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:24:06 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_env(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		printf("%s\n", env[i]);
}

static void	ft_print_exit(char **cmd)
{
	int	j;

	j = -1;
	while (cmd[1][++j])
	{
		if (ft_isdigit(cmd[1][j]) == 0)
		{
			printf("exit: %s%s\n", cmd[1], ERR_EXIT_N);
			exit (255);
		}
	}
}

static void	ft_exit2(t_pipe *p, t_data *data, int i)
{
	int	ex;

	if (i == 2)
	{
		ex = ft_atoi(p->cmd[1]);
		ft_free_pipe(p);
		ft_free_data(data, p->cmd[0]);
		exit (ex);
	}
	else
	{
		printf("exit: %s\n", ERR_EXIT);
		*(data->ex_s) = 1;
		return ;
	}
}

void	ft_exit(t_pipe *p, t_data *data)
{
	int	i;

	printf("exit\n");
	i = 0;
	while (p->cmd[i])
		i++;
	if (i == 1)
	{
		ft_free_pipe(p);
		ft_free_data(data, p->cmd[0]);
		exit(0);
	}
	else if (i >= 2)
	{
		ft_print_exit(p->cmd);
		ft_exit2(p, data, i);
	}
	*(data->ex_s) = 0;
}

int	ft_unset2(t_pipe *p, t_data *data, int mode, int *c_env)
{
	int	i;
	int	r;

	i = 1;
	r = 0;
	while (p->cmd[i])
	{
		if (ft_chk_dup(p->cmd[i], data->env) == 0)
			c_env--;
		else if (mode == 1 && ((p->cmd[i][0] <= 'A' || p->cmd[i][0] >= 'Z') \
			&& (p->cmd[i][0] <= 'a' || p->cmd[i][0] >= 'z') \
			&& p->cmd[i][0] != '_'))
		{
			printf("unset: %c%s\'%s\n", 96, p->cmd[i], ERR_EXPORT);
			r = 1;
		}
		i++;
	}
	return (r);
}
