/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:16:36 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:16:37 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free_c2d(char **s)
{
	int	i;

	i = -1;
	while (s[++i])
		free(s[i]);
	free(s);
}

void	ft_free_i2d(int **s, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(s[i]);
	free(s);
}

void	ft_free_data(t_data *data, char *s)
{
	if (data->path != NULL)
		ft_free_c2d(data->path);
	free(data->child_pid);
	if (ft_strncmpp(s, "exit", 4) == 0)
		ft_free_c2d(data->env);
	if (data->count_cmd > 1)
		ft_free_i2d(data->fd_pipe, data->count_cmd - 1);
}

void	ft_free_pipe(t_pipe *pipe)
{
	if (pipe->path != NULL)
		free(pipe->path);
}
