/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:13:54 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:13:55 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_instcmdtopar(t_shell *shell, t_par *par, int ststlen, int j)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (i < ststlen)
	{
		if (shell->lex->lextable[j][i] != NULL)
		{
			par->cmd[k] = ft_strdup(shell->lex->lextable[j][i]);
			free (shell->lex->lextable[j][i]);
			shell->lex->lextable[j][i] = NULL;
			k++;
		}
		i++;
	}
}

void	ft_parinsert2(char **str, t_parinsert *tmp, t_par *par, t_cmd *tcmd)
{
	if (str[tmp->i - 1] && str[tmp->i - 1][1] == '<')
		tcmd->sign_i[tmp->j] = 2;
	else
		tcmd->sign_i[tmp->j] = 1;
	par->i_tab[tmp->j] = ft_strdup(str[tmp->i]);
	free (str[tmp->i]);
	str[tmp->i] = NULL;
	free (str[tmp->i - 1]);
	str[tmp->i - 1] = NULL;
	tmp->i++;
	tmp->j++;
}

void	ft_parinsert_init(t_parinsert *tmp, char **str)
{
	tmp->k = 0;
	tmp->j = 0;
	tmp->i = 0;
	tmp->l = ft_strstrlen(str);
}
