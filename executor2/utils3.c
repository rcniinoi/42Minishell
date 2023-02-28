/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:15:31 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:15:33 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen_i(int *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}

void	ft_strlcpyy(char *dst, char *src, int size)
{
	int	i;

	if (size > 0)
	{
		i = 0;
		while (i < size && src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
}

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

char	*ft_itoaa(int n)
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

void	ft_strlcatt(char *dst, char *src, int size)
{
	int	i;
	int	j;
	int	d_len;

	d_len = ft_strlenn(dst);
	i = d_len;
	if (i < size - 1 && size > 0)
	{
		j = 0;
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
}
