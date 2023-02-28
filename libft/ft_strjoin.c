/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchiewli <rchiewli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:59:28 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/11 18:47:22 by rchiewli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*m;
	size_t	sumlen;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	m = (char *)malloc((sumlen + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < sumlen)
	{
		if (i < ft_strlen(s1))
			m[i] = s1[i];
		else
			m[i] = s2[j++];
		i++;
	}
	m[i] = '\0';
	free ((void *)s1);
	return (m);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*m;
	size_t	sumlen;
	size_t	i;
	size_t	j;

	if (s1 == NULL || s2 == NULL)
		return (0);
	sumlen = ft_strlen(s1) + ft_strlen(s2);
	m = (char *)malloc((sumlen + 1) * sizeof(char));
	if (m == NULL)
		return (0);
	i = 0;
	j = 0;
	while (i < sumlen)
	{
		if (i < ft_strlen(s1))
			m[i] = s1[i];
		else
			m[i] = s2[j++];
		i++;
	}
	m[i] = '\0';
	return (m);
}
