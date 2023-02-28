/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:11:33 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 02:42:18 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_shell	*ft_shellini(t_shell *shell)
{
	shell->decor = malloc(sizeof(t_decor));
	shell->exp = NULL;
	shell->par = NULL;
	shell->tcmd = NULL;
	return (shell);
}

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;

	rl_catch_signals = 0;
	shell = malloc(sizeof(t_shell));
	shell = ft_shellini(shell);
	ft_promptpare(ac, av, shell);
	shell->decor->fullpmt = ft_strjoin(shell->decor->pmptclr, \
								shell->decor->pmptstr);
	shell->decor->pmptfull = ft_strjoinfree(shell->decor->fullpmt, \
								shell->decor->inpclr);
	ft_signals();
	ft_submain(shell, env);
	free (shell->decor->pmptfull);
	free(shell->decor);
	free(shell->lex);
	free(shell);
	rl_clear_history();
	return (0);
}
