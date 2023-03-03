/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:27:27 by pmikada           #+#    #+#             */
/*   Updated: 2023/03/03 22:51:03 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_envargetter_2(t_envargetter *tmp, char **cmd, int i)
{
	tmp->j++;
	while (cmd[i][tmp->j] && (ft_isalnum(cmd[i][tmp->j]) == 1 || \
		cmd[i][tmp->j] == '?'))
	{
		tmp->evchar[tmp->k] = cmd[i][tmp->j];
		tmp->k++;
		tmp->j++;
	}
	tmp->evchar[tmp->k] = '\0';
}

char	*ft_envargetter(char **cmd, int i)
{
	t_envargetter	tmp;

	tmp.evchar = calloc(ft_strlen(cmd[i]) + 1, sizeof(char));
	tmp.k = 0;
	tmp.j = 0;
	while (cmd[i][tmp.j])
	{
		if (cmd[i][tmp.j] == '\'')
			break ;
		else if (cmd[i][tmp.j] == '$')
		{
			ft_envargetter_2(&tmp, cmd, i);
			break ;
		}
		tmp.j++;
	}
	return (tmp.evchar);
}

static void	ft_expander_2(t_exp *exptmp, t_par *partmp, char **env, int *exit_s)
{
	int	i;

	i = 0;
	while (partmp->cmd[i] != NULL)
	{
		exptmp->envar[i] = ft_envargetter(partmp->cmd, i);
		exptmp->envar[i + 1] = NULL;
		exptmp->fullvar[i] = ft_envcompare(exptmp->envar[i], env, exit_s);
		exptmp->fullvar[i + 1] = NULL;
		i++;
	}
}

static void	ft_expander_3(t_exp *exptmp, t_par *partmp, char **env, int *exit_s)
{
	int	i;

	i = 0;
	while (partmp->i_tab[i])
	{
		exptmp->i_tab[i] = ft_envargetter(partmp->i_tab, i);
		exptmp->i_tab[i + 1] = NULL;
		exptmp->full_i[i] = ft_envcompare(exptmp->i_tab[i], env, exit_s);
		exptmp->full_i[i + 1] = NULL;
		i++;
	}
}

int	ft_expander(t_shell *shell, char **env, int *exit_s)
{
	int		i;
	t_exp	*exptmp;
	t_par	*partmp;

	partmp = shell->par;
	while (partmp != NULL)
	{
		exptmp = ft_expini(shell);
		ft_expander_2(exptmp, partmp, env, exit_s);
		ft_expander_3(exptmp, partmp, env, exit_s);
		i = 0;
		while (partmp->o_tab[i])
		{
			exptmp->o_tab[i] = ft_envargetter(partmp->o_tab, i);
			exptmp->o_tab[i + 1] = NULL;
			exptmp->full_o[i] = ft_envcompare(exptmp->o_tab[i], env, exit_s);
			exptmp->full_o[i + 1] = NULL;
			i++;
		}
		partmp = partmp->next;
	}
	return (0);
}
