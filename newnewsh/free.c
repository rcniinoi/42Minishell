/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:45:41 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:45:42 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free2(char ***dptr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dptr[i][j])
	{
		if (dptr[i][j])
		{
			free(dptr[i][j]);
			dptr[i][j] = NULL;
		}
		j++;
	}
	free(dptr[i]);
	dptr[i] = NULL;
}

void	ft_freeexp(t_shell	*shell)
{
	t_exp	**exptmp;
	t_exp	*exptmp2;

	exptmp = &shell->exp;
	while (*exptmp != NULL)
	{
		ft_free2(&((*exptmp)->envar));
		ft_free2(&((*exptmp)->fullvar));
		ft_free2(&((*exptmp)->i_tab));
		ft_free2(&((*exptmp)->full_i));
		ft_free2(&((*exptmp)->o_tab));
		ft_free2(&((*exptmp)->full_o));
		exptmp2 = (*exptmp)->next;
		if (*exptmp)
		{
			free ((*exptmp));
			((*exptmp)) = NULL;
		}
		*exptmp = exptmp2;
	}
}

void	ft_freepar(t_shell *shell)
{
	t_par	**partmp;
	t_par	*partmp2;

	partmp = &shell->par;
	while (*partmp != NULL)
	{
		ft_free2(&((*partmp)->i_tab));
		ft_free2(&((*partmp)->o_tab));
		ft_free2(&((*partmp)->cmd));
		partmp2 = (*partmp)->next;
		if (*partmp)
		{
			free((*partmp));
			(*partmp) = NULL;
		}
		*partmp = partmp2;
	}
}

void	ft_freetcmd(t_shell *shell)
{
	t_cmd	**cmdtmp;
	t_cmd	*cmdtmp2;

	cmdtmp = &shell->tcmd;
	while (*cmdtmp != NULL)
	{
		free ((*cmdtmp)->sign_i);
		free ((*cmdtmp)->sign_o);
		ft_free2(&((*cmdtmp)->i_tab));
		ft_free2(&((*cmdtmp)->o_tab));
		ft_free2(&((*cmdtmp)->cmd));
		cmdtmp2 = (*cmdtmp)->next;
		if (*cmdtmp)
		{
			free((*cmdtmp));
			(*cmdtmp) = NULL;
		}
		*cmdtmp = cmdtmp2;
	}
}
