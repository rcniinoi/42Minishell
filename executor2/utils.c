/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:16:18 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:16:20 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlenn(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_c2d(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpyy(void *dst, void *src, int n)
{
	int	i;

	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdupp(char *s1)
{
	int		len;
	char	*m;

	len = ft_strlenn(s1);
	m = (char *)malloc((len * sizeof(char)) + 1);
	if (m == NULL)
		return (0);
	ft_memcpyy(m, s1, len);
	m[len] = '\0';
	return (m);
}

int	ft_strncmpp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (ft_strlenn(s2) == 0 || ft_strlenn(s1) == 0)
		return (1);
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
