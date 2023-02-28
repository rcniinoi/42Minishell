/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:50:56 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 03:18:12 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	ft_tmp_env(t_data *data, char **env)
{
	int	len;
	int	i;

	len = ft_strlen_c2d(env);
	data->env = malloc(sizeof(char *) * (len + 1));
	if (data->env == NULL)
		return ;
	i = -1;
	while (env[++i])
		data->env[i] = ft_strdupp(env[i]);
	data->env[i] = NULL;
}

static void	ft_free_sub(t_shell *shell)
{
	int	x;

	x = -1;
	while (shell->lex->lextable[++x])
		free(shell->lex->lextable[x]);
	free(shell->lex->lextable);
	free(shell->lex->trimstr);
	ft_freepar(shell);
	ft_freeexp(shell);
	ft_freetcmd(shell);
}

static int	ft_chk(t_shell *shell, int *exit_s)
{
	int	i;

	i = -1;
	while (shell->lex->lexed[++i])
	{
		if (ft_issymbol(shell->lex->lexed[i][0], '<') == 1 || \
			ft_issymbol(shell->lex->lexed[i][0], '>') == 1)
		{
			if (shell->lex->lexed[i + 1] == NULL || \
				ft_isarrowpipe(shell->lex->lexed[i + 1][0]) == 1)
			{
				printf("syntax error near unexpected token\n");
				*exit_s = 258;
				free(shell->lex->trimstr);
				return (1);
			}
		}
	}
	return (0);
}

static void	ft_submain2(t_shell *shell, t_data *data, int *exit_s)
{
	int	len;

	len = 0;
	add_history(shell->lex->allstr);
	shell->lex->trimstr = ft_strtrim(shell->lex->allstr, " ");
	len = ft_strlen(shell->lex->trimstr);
	ft_lexmain(shell, 0, len);
	if (ft_chk(shell, exit_s))
		return ;
	ft_parser(shell);
	ft_expander(shell, data->env, exit_s);
	ft_exptostr(shell);
	ft_executor(shell->tcmd, data, exit_s);
	ft_free_sub(shell);
}

int	ft_submain(t_shell *shell, char **env)
{
	t_data	data;
	int		exit_s;

	shell->lex = malloc(sizeof(t_lex));
	ft_tmp_env(&data, env);
	exit_s = 0;
	while (1)
	{
		shell->lex->lexed = malloc(sizeof(char *) * 1000);
		if (shell->lex->lexed == NULL)
			return (0);
		shell->lex->allstr = readline(shell->decor->pmptfull);
		if (shell->lex->allstr == NULL)
		{
			free(shell->lex->allstr);
			exit (0);
		}
		if (ft_strlen(shell->lex->allstr) > 0)
			ft_submain2(shell, &data, &exit_s);
		free(shell->lex->lexed);
		free(shell->lex->allstr);
	}
	return (0);
}
