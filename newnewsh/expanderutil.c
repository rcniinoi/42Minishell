/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expanderutil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:17:58 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:17:59 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_exp	*ft_expini(t_shell *shell)
{
	t_exp	*tmp;
	int		x;

	x = 0;
	tmp = ft_expmaker(shell);
	tmp->i_tab = malloc(sizeof(char *) * 100);
	tmp->o_tab = malloc(sizeof(char *) * 100);
	tmp->envar = malloc(sizeof(char *) * 100);
	tmp->full_i = malloc(sizeof(char *) * 100);
	tmp->full_o = malloc(sizeof(char *) * 100);
	tmp->fullvar = malloc(sizeof(char *) * 100);
	while (x < 100)
	{
		tmp->i_tab[x] = NULL;
		tmp->o_tab[x] = NULL;
		tmp->envar[x] = NULL;
		tmp->full_i[x] = NULL;
		tmp->full_o[x] = NULL;
		tmp->fullvar[x] = NULL;
		x++;
	}
	return (tmp);
}

t_exp	*ft_expmaker(t_shell *shell)
{
	t_exp	*new;
	t_exp	*tmp;

	new = malloc(sizeof(t_exp));
	if (shell->exp == NULL)
	{
		shell->exp = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		tmp = shell->exp;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = tmp;
	}
	return (new);
}

t_cmd	*ft_finini(t_shell *shell)
{
	t_cmd	*tmp;
	int		len;

	len = ft_strstrlen(shell->par->cmd);
	tmp = ft_finmaker(shell);
	tmp->cmd = malloc(sizeof(char *) * (len + 1));
	tmp->cmd[len] = NULL;
	len = ft_strstrlen(shell->par->i_tab);
	tmp->i_tab = malloc(sizeof(char *) * (len + 1));
	tmp->i_tab[len] = NULL;
	tmp->sign_i = malloc(sizeof(int) * len);
	len = ft_strstrlen(shell->par->o_tab);
	tmp->o_tab = malloc(sizeof(char *) * (len + 1));
	tmp->o_tab[len] = NULL;
	tmp->sign_o = malloc(sizeof(int) * len);
	return (tmp);
}

t_cmd	*ft_finmaker(t_shell *shell)
{
	t_cmd	*new;
	t_cmd	*tmp;

	new = malloc(sizeof(t_cmd));
	if (shell->tcmd == NULL)
	{
		shell->tcmd = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		tmp = shell->tcmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = tmp;
	}
	return (new);
}
