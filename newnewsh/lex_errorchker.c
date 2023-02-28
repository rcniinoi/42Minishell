/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_errorchker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:17:43 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:17:45 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_chkandgo(t_lex *lex)
{
	if (ft_strlen(lex->trimstr) > 0 && ft_isclosequote(lex) > -1 && \
		ft_triplearrow(lex) > -1 && ft_triplepipe(lex) > -1)
		return (1);
	else
		return (0);
}

int	ft_isclosequote(t_lex *lex)
{
	int	i;
	int	q;

	i = 0;
	q = 0;
	while (lex->allstr[i])
	{
		if ((lex->allstr[i] == '\'' || lex->allstr[i] == '\"') && q == 0)
		{
			if (lex->allstr[i] == '\'')
				q = 1;
			else if (lex->allstr[i] == '\"')
				q = 2;
		}
		else if ((lex->allstr[i] == '\'' || lex->allstr[i] == '\"') && q != 0)
		{
			if ((lex->allstr[i] == '\'' && q == 1) || \
				(lex->allstr[i] == '\"' && q == 2))
				q = 0;
		}
		i++;
	}
	if (q != 0)
		return (-1);
	return (i);
}

int	ft_triplearrow(t_lex *lex)
{
	int	i;

	i = 0;
	while (lex->trimstr[i])
	{
		if (lex->trimstr[i] == '>')
		{
			if (lex->trimstr[i + 1] == '>' && lex->trimstr[i + 2] == '>')
				return (-1);
		}
		else if (lex->trimstr[i] == '<')
		{
			if (lex->trimstr[i + 1] == '<' && lex->trimstr[i + 2] == '<')
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_triplepipe(t_lex *lex)
{
	int	i;

	i = 0;
	while (lex->trimstr[i])
	{
		if (lex->trimstr[i] == '|')
		{
			if (lex->trimstr[i + 1] == '|' && lex->trimstr[i + 2] == '|')
				return (-1);
		}
		i++;
	}
	return (0);
}
