/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n_l_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:26:46 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/04 19:26:48 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen_g(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_nl_g(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (i);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char	*m;
	int		sumlen;
	int		s1_len;
	int		i;
	int		j;

	s1_len = ft_strlen_g(s1);
	sumlen = s1_len + ft_strlen_g(s2);
	m = (char *)malloc((sumlen * sizeof(char)) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < sumlen)
	{
		if (i < s1_len)
			m[i] = s1[i];
		else
			m[i] = s2[j++];
		i++;
	}
	m[i] = '\0';
	if (s1 != NULL)
		free(s1);
	return (m);
}

char	*ft_strdup_g(char *s)
{
	char	*m;
	int		len;
	int		i;

	len = ft_strlen_nl_g(s);
	if (len == -1)
		len = ft_strlen_g(s);
	m = (char *)malloc((len * sizeof(char)) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		m[i] = s[i];
		i++;
	}
	m[i] = '\0';
	if (m[0] == '\0')
	{
		free(m);
		return (NULL);
	}
	return (m);
}
