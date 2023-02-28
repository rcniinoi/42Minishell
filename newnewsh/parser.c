/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:18:39 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:18:40 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strstrlen(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (i);
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_choosecount(char	**lex, char a)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (lex[i])
	{
		if (lex[i][0] == a)
			count++;
		i++;
	}
	return (count);
}

void	ft_pipecutter_init(t_parinsert *tmp)
{
	tmp->i = 0;
	tmp->j = 0;
	tmp->k = 0;
	tmp->l = tmp->i;
}

static void	ft_pipecutter(t_lex *lex, int pipec)
{
	t_parinsert	tmp;

	ft_pipecutter_init(&tmp);
	lex->lextable = malloc(sizeof(char **) * (pipec + 2));
	while (lex->lexed[tmp.i])
	{
		if (lex->lexed[tmp.i + 1] == NULL || lex->lexed[tmp.i + 1][0] == '|')
		{
			lex->lextable[tmp.j] = malloc(sizeof(char *) * (tmp.i - tmp.l + 2));
			while (tmp.l <= tmp.i)
			{
				lex->lextable[tmp.j][tmp.k] = ft_strdup(lex->lexed[tmp.l]);
				tmp.l++;
				tmp.k++;
			}
			lex->lextable[tmp.j][tmp.k] = NULL;
			tmp.k = 0;
			tmp.j++;
			tmp.l = tmp.i + 2;
		}
		tmp.i++;
	}
	lex->lextable[tmp.j] = NULL;
}

int	ft_parser(t_shell *shell)
{
	t_par		*now;
	int			scmdlen;
	t_cmd		*tcmd;
	t_parinsert	tmp;

	scmdlen = 0;
	tmp.i = 0;
	tmp.j = ft_choosecount(shell->lex->lexed, '|');
	ft_strstrlen(shell->lex->lexed);
	ft_pipecutter(shell->lex, tmp.j);
	tmp.l = -1;
	while (shell->lex->lexed[++tmp.l] != NULL)
		free(shell->lex->lexed[tmp.l]);
	while (shell->lex->lextable[tmp.i] != NULL)
	{
		scmdlen = ft_strstrlen(shell->lex->lextable[tmp.i]);
		now = ft_parini(shell, tmp.i);
		tcmd = ft_tcmdini(shell, tmp.i);
		ft_parinsert(now, tcmd, shell->lex->lextable[tmp.i]);
		ft_instcmdtopar(shell, now, scmdlen, tmp.i);
		tmp.i++;
	}
	return (0);
}
