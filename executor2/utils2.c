/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:15:57 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:15:58 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_count_word(char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			word++;
		i++;
	}
	return (word);
}

static char	*ft_loc_string(char *s, int start, int end)
{
	char	*m;
	int		i;

	i = 0;
	m = (char *)malloc((end - start + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	while (start < end)
		m[i++] = s[start++];
	m[i] = '\0';
	return (m);
}

char	**ft_splitt(char *s, char c)
{
	char	**m;
	int		i;
	int		start;
	int		word;

	if (s == NULL)
		return (0);
	m = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (m == NULL)
		return (0);
	i = 0;
	word = 0;
	while (i <= ft_strlenn(s))
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (i != 0 && s[i - 1] != c && (s[i] == c || s[i] == '\0'))
			m[word++] = ft_loc_string(s, start, i);
		i++;
	}
	m[word] = 0;
	return (m);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*m;
	int		sumlen;
	int		i;
	int		j;

	sumlen = ft_strlenn(s1) + ft_strlenn(s2);
	m = (char *)malloc((sumlen + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < sumlen)
	{
		if (i < ft_strlenn(s1))
			m[i] = s1[i];
		else
			m[i] = s2[j++];
		i++;
	}
	m[i] = '\0';
	free(s1);
	return (m);
}

char	*ft_strjoinn(char *s1, char *s2)
{
	char	*m;
	int		sumlen;
	int		i;
	int		j;

	sumlen = ft_strlenn(s1) + ft_strlenn(s2);
	m = (char *)malloc((sumlen + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < sumlen)
	{
		if (i < ft_strlenn(s1))
			m[i] = s1[i];
		else
			m[i] = s2[j++];
		i++;
	}
	m[i] = '\0';
	return (m);
}
