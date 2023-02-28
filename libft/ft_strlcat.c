/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:26:27 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/06 18:47:41 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destsize)
{
	size_t	i;
	size_t	j;
	size_t	d_len;

	d_len = ft_strlen(dst);
	i = d_len;
	if (i < destsize - 1 && destsize > 0)
	{
		j = 0;
		while (src[j] && i < destsize - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	if (d_len >= destsize)
		return (ft_strlen(src) + destsize);
	else
		return (ft_strlen(src) + d_len);
}
