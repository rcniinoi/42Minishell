/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_util3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:17:58 by pmikada           #+#    #+#             */
/*   Updated: 2023/03/03 23:20:36 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_qchk(char *cstr, int *i)
{
	if (cstr[*i] && cstr[*i] == '\'')
		return (1);
	else if (cstr[*i] && cstr[*i] == '\"')
		return (2);
	else
		return (0);
}

static void	ft_subqcut(char *cstr, int *i, int *j, char *rst)
{
	int	q;

	q = ft_qchk(cstr, i);
	*i += 1;
	if (q == 1)
	{
		while (cstr[*i] && cstr[*i] != '\'')
		{
			rst[*j] = cstr[*i];
			*j += 1;
			*i += 1;
		}
	}
	else if (q == 2)
	{
		while (cstr[*i] && cstr[*i] != '\"')
		{
			rst[*j] = cstr[*i];
			*j += 1;
			*i += 1;
		}
	}
}

char	*ft_quotecut(char *cstr)
{
	int		i;
	int		j;
	char	*rst;

	rst = ft_calloc(100, sizeof(char));
	i = 0;
	j = 0;
	cstr = ft_ecprcut(cstr);
	while (cstr[i])
	{
		while (cstr[i] && ft_isquote(cstr[i]) == 0)
		{
			rst[j] = cstr[i];
			j++;
			i++;
		}
		ft_subqcut(cstr, &i, &j, rst);
	}
	rst[i] = '\0';
	free (cstr);
	cstr = NULL;
	return (rst);
}

void	ft_tant(t_shell *shell)
{
	int	i;

	i = -1;
	while (shell->tcmd->cmd[++i])
		shell->tcmd->cmd[i] = ft_quotecut(shell->tcmd->cmd[i]);
	i = -1;
	while (shell->tcmd->i_tab[++i])
		shell->tcmd->i_tab[i] = ft_quotecut(shell->tcmd->i_tab[i]);
	i = -1;
	while (shell->tcmd->o_tab[++i])
		shell->tcmd->o_tab[i] = ft_quotecut(shell->tcmd->o_tab[i]);
}

char	*ft_ecprcut(char *cstr)
{
	int		i;
	char	*rst;
	int		j;

	j = 0;
	rst = ft_calloc(100, sizeof(char));
	i = 0;
	while (cstr[i] && ft_isquote(cstr[i]) != 1)
		i++;
	if (cstr[i] != '\0')
		return (cstr);
	i = 0;
	while (cstr[i])
	{
		while (cstr[i] && cstr[i] != '\\')
			rst[j++] = cstr[i++];
		if (cstr[i] == '\\')
			i++;
	}
	free (cstr);
	cstr = NULL;
	return (rst);
}
