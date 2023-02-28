/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexor_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:17:27 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:17:28 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isspace(int c)
{
	c = (unsigned char)c;
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_isarrowpipe(int c)
{
	if (ft_issymbol(c, '<') == 1 || \
		ft_issymbol(c, '>') == 1 || \
		ft_issymbol(c, '|') == 1)
		return (1);
	return (0);
}

int	ft_isquote(int c)
{
	if (ft_issymbol(c, '\'') || ft_issymbol(c, '\"'))
		return (1);
	return (0);
}

int	ft_issymbol(int c, char sym)
{
	if (c == sym)
		return (1);
	return (0);
}

void	ft_nextlex_init(t_intvar *inv, int start, int *e, t_lex *tall)
{
	inv->q = 0;
	inv->i = start;
	inv->st = 0;
	inv->ed = ft_strlen(tall->trimstr);
	*e = 0;
}
