/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 18:39:16 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/09 20:31:47 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*m;
	size_t	i;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start + len)
		m = (char *)malloc(1 * sizeof(char));
	else
		m = (char *)malloc((len + 1) * sizeof (char));
	if (m == NULL)
		return (0);
	i = 0;
	while (s[start + i] && i < len && start < ft_strlen(s))
	{
		m[i] = s[start + i];
		i++;
	}
	m[i] = '\0';
	return (m);
}
