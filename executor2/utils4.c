/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:14:54 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:14:57 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmpp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	if (ft_strlenn(s1) - 1 != ft_strlenn(s2))
		return (0);
	while (i < size - 1)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlen_2(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '=' && s[i])
		i++;
	return (i);
}
