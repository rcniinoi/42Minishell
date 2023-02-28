/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:29:48 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:29:50 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_nextlex2(t_intvar *inv, t_lex *tall)
{
	while (inv->i < inv->ed)
	{
		if (!ft_isspace(tall->trimstr[inv->i]))
		{
			inv->st += inv->i;
			break ;
		}
		inv->i++;
	}
}

static void	ft_nextlex3(t_intvar *inv, t_lex *tall)
{
	if (ft_issymbol(tall->trimstr[inv->i], '<') == 1)
		inv->q = RE_INPUT;
	else if (ft_issymbol(tall->trimstr[inv->i], '>') == 1)
		inv->q = RE_OUTPUT;
	inv->st = inv->i;
	inv->ed = inv->i + 1;
	if (((ft_issymbol(tall->trimstr[inv->i + 1], '<') == 1) && \
		inv->q == RE_INPUT) || \
		((ft_issymbol(tall->trimstr[inv->i + 1], '>') == 1) \
		&& inv->q == RE_OUTPUT))
		inv->ed += 1;
	inv->q = 0;
}

static void	ft_nextlex4(t_intvar *inv, t_lex *tall)
{
	while (1)
	{
		if (ft_isquote(tall->trimstr[inv->i]) == 1)
		{
			if (ft_issymbol(tall->trimstr[inv->i], '\'') == 1 && inv->q == 0)
				inv->q = 1;
			else if (ft_issymbol(tall->trimstr[inv->i], '\"') == 1 \
				&& inv->q == 0)
				inv->q = 2;
			else if ((ft_issymbol(tall->trimstr[inv->i], '\'') == 1 \
				&& inv->q == 1) \
				|| (ft_issymbol(tall->trimstr[inv->i], '\"') == 1 \
				&& inv->q == 2))
				inv->q = 0;
		}
		if ((!inv->q && (ft_isarrowpipe(tall->trimstr[inv->i]) == 1 \
			|| ft_isspace(tall->trimstr[inv->i]) == 1)) \
			|| !tall->trimstr[inv->i])
		{
			inv->ed = inv->i;
			break ;
		}
		inv->i++;
	}
}

int	ft_nextlex(t_lex *tall, int start, int times)
{
	t_intvar	inv;
	int			e;

	ft_nextlex_init(&inv, start, &e, tall);
	ft_nextlex2(&inv, tall);
	if (ft_isarrowpipe(tall->trimstr[inv.i]) == 1)
		ft_nextlex3(&inv, tall);
	else
		ft_nextlex4(&inv, tall);
	tall->lexed[times] = calloc(((inv.ed - inv.st) + 1), sizeof(char *));
	ft_memcpy(tall->lexed[times], &tall->trimstr[inv.st], inv.ed - inv.st);
	tall->lexed[times + 1] = NULL;
	e = inv.ed;
	return (e);
}

int	ft_lexmain(t_shell *shell, int start, int len)
{
	int	i;

	i = 0;
	start = ft_nextlex(shell->lex, start, i);
	if (ft_chkandgo(shell->lex) == 1)
	{
		while (start < len)
		{
			i++;
			start = ft_nextlex(shell->lex, start, i);
		}
	}
	return (0);
}
