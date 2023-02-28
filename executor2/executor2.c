/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:50:46 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:50:47 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_chk_io_file(t_cmd *cmd, int *ex_s)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (ft_strlen_c2d(tmp->i_tab) != ft_strlen_i(tmp->sign_i) || \
			ft_strlen_c2d(tmp->o_tab) != ft_strlen_i(tmp->sign_o))
		{
			printf("syntax error near unexpected token\n");
			*ex_s = 258;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
