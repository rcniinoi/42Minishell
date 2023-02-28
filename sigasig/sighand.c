/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 06:14:34 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 06:14:35 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_handler(int signo, siginfo_t *s, void *old)
{
	(void) old;
	(void) s;
	if (signo == SIGINT)
	{
		ft_putstr_fd("\n", STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
		return ;
}

void	ft_signals(void)
{
	struct sigaction	kasig;
	struct sigaction	kaboom;

	kasig.sa_sigaction = ft_handler;
	kaboom.sa_handler = SIG_IGN;
	kasig.sa_flags = SA_SIGINFO;
	kaboom.sa_flags = SA_RESTART;
	sigemptyset(&kasig.sa_mask);
	sigemptyset(&kaboom.sa_mask);
	sigaction(SIGINT, &kasig, 0);
	sigaction(SIGQUIT, &kaboom, 0);
}
