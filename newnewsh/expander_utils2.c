/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 05:31:46 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 02:51:09 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_exptostr2(t_par *tpar, t_exp *texp, t_cmd *tfin)
{
	int	i;

	i = 0;
	while (tpar->cmd[i] != NULL)
	{
		if (texp->envar[i][0] == '\0' && tpar->cmd[i][0] != '\0')
			tfin->cmd[i] = ft_strdup(tpar->cmd[i]);
		else if (texp->fullvar[i][0] == '\0' && texp->envar[i][0] != '\'')
			tfin->cmd[i] = ft_strdup(texp->fullvar[i]);
		else if (texp->fullvar[i][0] != '\0')
			tfin->cmd[i] = ft_putpath(tpar->cmd, texp->envar, \
				texp->fullvar, i);
		else
			tfin->cmd[i] = ft_strdup(tpar->cmd[i]);
		i++;
	}
}

static void	ft_exptostr3(t_par *tpar, t_exp *texp, t_cmd *tfin)
{
	int	i;

	i = 0;
	while (texp->full_i[i] != NULL)
	{
		if (texp->i_tab[i][0] == '\0' && tpar->i_tab[i][0] != '\0')
			tfin->i_tab[i] = ft_strdup(tpar->i_tab[i]);
		else if (texp->full_i[i][0] == '\0' && texp->i_tab[i][0] != '\'')
			tfin->i_tab[i] = ft_strdup(texp->full_i[i]);
		else if (texp->full_i[i][0] != '\0')
			tfin->i_tab[i] = ft_putpath(tpar->i_tab, texp->i_tab, \
				texp->full_i, i);
		else
			tfin->i_tab[i] = ft_strdup(tpar->i_tab[i]);
		i++;
	}
}

static void	ft_exptostr4(t_par *tpar, t_exp *texp, t_cmd *tfin)
{
	int	i;

	i = 0;
	while (texp->full_o[i] != NULL)
	{
		if (texp->o_tab[i][0] == '\0' && tpar->o_tab[i][0] != '\0')
			tfin->o_tab[i] = ft_strdup(tpar->o_tab[i]);
		else if (texp->full_o[i][0] == '\0' && texp->o_tab[i][0] != '\'')
			tfin->o_tab[i] = ft_strdup(texp->full_o[i]);
		else if (texp->full_o[i][0] != '\0')
			tfin->o_tab[i] = ft_putpath(tpar->o_tab, \
				texp->o_tab, texp->full_o, i);
		else
			tfin->o_tab[i] = ft_strdup(tpar->o_tab[i]);
		i++;
	}
}

int	ft_exptostr(t_shell *shell)
{
	t_par	*tpar;
	t_exp	*texp;
	t_cmd	*tfin;

	tfin = shell->tcmd;
	tpar = shell->par;
	texp = shell->exp;
	while (tpar != NULL)
	{
		ft_exptostr2(tpar, texp, tfin);
		ft_exptostr3(tpar, texp, tfin);
		ft_exptostr4(tpar, texp, tfin);
		texp = texp->next;
		tpar = tpar->next;
		tfin = tfin->next;
	}
	return (0);
}
