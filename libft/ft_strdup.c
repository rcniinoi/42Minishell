/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 19:33:41 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/08 19:51:07 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*m;

	len = ft_strlen(s1);
	m = (char *)malloc((len * sizeof(char)) + 1);
	if (m == NULL)
		return (0);
	ft_memcpy(m, s1, len);
	m[len] = '\0';
	return (m);
}
