/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:10:36 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/18 00:23:52 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *s, char c)
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

static char	*ft_loc_string(char const *s, int start, int end)
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

char	**ft_split(char const *s, char c)
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
	while (i <= (int)ft_strlen(s))
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
