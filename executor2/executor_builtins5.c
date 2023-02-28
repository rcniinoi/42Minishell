/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor_builtins5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:43:32 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:43:38 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_add_export2(int *i, int mode, t_pipe *p, char **n_env)
{
	int	r;
	int	j;

	r = 0;
	j = 1;
	while (p->cmd[j])
	{
		if (((p->cmd[j][0] >= 'A' && p->cmd[j][0] <= 'Z') \
			|| (p->cmd[j][0] >= 'a' && p->cmd[j][0] <= 'z') \
			|| p->cmd[j][0] == '_'))
			ft_insert_export(i, j, p, n_env);
		else if (mode == 1)
		{
			printf("export: %c%s\'%s\n", 96, p->cmd[j], ERR_EXPORT);
			r = 1;
		}
		j++;
	}
	return (r);
}
