/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_fork3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:16:52 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:16:53 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_chk_builtins(char *cmd)
{
	if (ft_strncmpp(cmd, "echo", 4) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "cd", 2) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "pwd", 3) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "export", 6) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "unset", 5) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "env", 3) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "exit", 4) == 0)
		return (0);
	else if (ft_strncmpp(cmd, "$?", 2) == 0)
		return (0);
	return (1);
}
