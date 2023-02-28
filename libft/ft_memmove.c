/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:10:08 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/17 23:57:39 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d == 0 && s == 0)
		return (0);
	if (d < s)
		return (ft_memcpy(dst, src, len));
	else
	{
		d = d + (len - 1);
		s = s + (len - 1);
		while (len-- > 0)
			*d-- = *s--;
	}
	return (dst);
}
