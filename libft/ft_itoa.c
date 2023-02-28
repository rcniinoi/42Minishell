/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:11:47 by pmikada           #+#    #+#             */
/*   Updated: 2022/06/18 00:27:45 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	count;

	count = 0;
	if (n < 0 && n != 0)
		count++;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*m;
	int				digit;
	long int		b_n;
	long int		temp_n;

	temp_n = n;
	digit = ft_count_digit(n);
	m = (char *)malloc(sizeof(char) * (digit + 1));
	if (m == NULL)
		return (0);
	b_n = temp_n;
	if (temp_n < 0)
		temp_n *= -1;
	m[digit] = '\0';
	while (digit != 0)
	{
		m[digit - 1] = '0' + (temp_n % 10);
		if (b_n < 0)
			m[0] = '-';
		temp_n /= 10;
		digit--;
	}
	return (m);
}
