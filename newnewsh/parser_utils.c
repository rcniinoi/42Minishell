/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:02:48 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:02:49 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_parinsert(t_par *par, t_cmd *tcmd, char **str)
{
	t_parinsert	tmp;

	ft_parinsert_init(&tmp, str);
	while (tmp.i < tmp.l && str[tmp.i] != NULL)
	{
		if (tmp.i > 0 && str[tmp.i - 1][0] == '<')
			ft_parinsert2(str, &tmp, par, tcmd);
		else if (tmp.i > 0 && str[tmp.i - 1][0] == '>')
		{
			if (str[tmp.i - 1] && str[tmp.i - 1][1] == '>')
				tcmd->sign_o[tmp.k] = 2;
			else
				tcmd->sign_o[tmp.k] = 1;
			par->o_tab[tmp.k] = ft_strdup(str[tmp.i]);
			free (str[tmp.i]);
			str[tmp.i] = NULL;
			free (str[tmp.i - 1]);
			str[tmp.i - 1] = NULL;
			tmp.i++;
			tmp.k++;
		}
		tmp.i++;
	}
}

static t_par	*ft_parmaker(t_shell *shell)
{
	t_par	*new;
	t_par	*tmp;

	new = malloc(sizeof(t_par));
	if (shell->par == NULL)
	{
		shell->par = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		tmp = shell->par;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
		new->prev = tmp;
	}
	return (new);
}

t_par	*ft_parini(t_shell *shell, int i)
{
	int		inputc;
	t_par	*tmp;
	int		j;

	j = 0;
	tmp = ft_parmaker(shell);
	tmp->cmd = malloc(sizeof(char *) * 100);
	while (j < 100)
		tmp->cmd[j++] = NULL;
	inputc = ft_choosecount(shell->lex->lextable[i], '<');
	tmp->i_tab = malloc(sizeof(char *) * (inputc + 1));
	tmp->i_tab[inputc] = NULL;
	inputc = ft_choosecount(shell->lex->lextable[i], '>');
	tmp->o_tab = malloc(sizeof(char *) * (inputc + 1));
	tmp->o_tab[inputc] = NULL;
	i++;
	return (tmp);
}

t_cmd	*ft_tcmdini(t_shell *shell, int i)
{
	t_cmd	*tmp;
	int		j;

	j = 0;
	tmp = ft_cmdmaker(shell);
	tmp->cmd = malloc(sizeof(char *) * 100);
	while (j < 100)
		tmp->cmd[j++] = NULL;
	tmp->in_count = ft_choosecount(shell->lex->lextable[i], '<');
	tmp->i_tab = malloc(sizeof(char *) * (tmp->in_count + 1));
	tmp->sign_i = ft_calloc(tmp->in_count + 10, sizeof(int));
	tmp->i_tab[tmp->in_count] = NULL;
	tmp->out_count = ft_choosecount(shell->lex->lextable[i], '>');
	tmp->o_tab = malloc(sizeof(char *) * (tmp->out_count + 1));
	tmp->sign_o = ft_calloc(tmp->out_count + 10, sizeof(int));
	tmp->o_tab[tmp->out_count] = NULL;
	i++;
	return (tmp);
}

t_cmd	*ft_cmdmaker(t_shell *shell)
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
