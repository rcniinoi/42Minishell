/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 03:28:59 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 03:16:53 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_envcompare(char *str, char **env, int *exit_s)
{
	int		len;
	int		i;
	char	*rst;

	rst = NULL;
	i = 0;
	len = ft_strlen(str);
	if (str[0] == '\0')
		return (ft_calloc(1, sizeof(char)));
	else if (ft_strncmp(str, "?", 1) == 0)
		return (ft_itoa(*exit_s));
	while (env[i] != NULL)
	{
		if (ft_strncmp(str, env[i], len) == 0)
		{
			rst = ft_strdup(ft_strchr(env[i], '=') + 1);
			break ;
		}
		i++;
	}
	if (env[i] == NULL)
		return (ft_calloc(1, sizeof(char)));
	return (rst);
}

void	ft_putpath2(t_parinsert *tmp, char **cmd, char *rst, int i)
{
	while (cmd[i][tmp->j] && cmd[i][tmp->j] != '$')
	{
		if (ft_isquote(cmd[i][tmp->j]) == 0)
		{
			rst[tmp->k] = cmd[i][tmp->j];
			tmp->k++;
		}
		tmp->j++;
	}
}

void	ft_putpath_init(t_parinsert *tmp, char *rst)
{
	(void)rst;
	tmp->l = 0;
	tmp->k = 0;
	tmp->j = 0;
}

char	*ft_putpath(char **cmd, char **envar, char **fullvar, int i)
{
	char		*rst;
	t_parinsert	tmp;

	tmp.i = ft_strlen(cmd[i]) - ft_strlen(envar[i]) + ft_strlen(fullvar[i]);
	rst = calloc((tmp.i + 1), sizeof(char));
	ft_putpath_init(&tmp, rst);
	ft_putpath2(&tmp, cmd, rst, i);
	while (fullvar[i][tmp.l])
	{
		rst[tmp.k] = fullvar[i][tmp.l];
		tmp.k++;
		tmp.l++;
	}
	tmp.j += (ft_strlen(envar[i]) + 1);
	while (cmd[i][tmp.j])
	{
		if (ft_isquote(cmd[i][tmp.j]) == 0)
		{
			rst[tmp.k] = cmd[i][tmp.j];
			tmp.k++;
		}
		tmp.j++;
	}
	return (rst);
}
