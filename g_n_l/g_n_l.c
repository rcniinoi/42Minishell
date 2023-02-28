/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n_l.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:18:32 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/04 19:18:34 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*ft_cut(t_buff *b)
{
	char	*m;
	int		diff;
	int		len_nl;
	int		i;

	len_nl = ft_strlen_nl_g(b->tmp_buff);
	if (len_nl == -1)
		len_nl = ft_strlen_g(b->tmp_buff);
	diff = ft_strlen_g(b->tmp_buff) - len_nl;
	m = (char *)malloc((diff * sizeof(char)) + 1);
	if (m == NULL)
		return (NULL);
	i = 0;
	while (i < diff)
		m[i++] = b->tmp_buff[len_nl++];
	m[i] = '\0';
	free(b->tmp_buff);
	if (m[0] == '\0')
	{
		free(m);
		return (NULL);
	}
	return (m);
}

static void	ft_re_buff(char **r_buff, t_buff *b)
{
	*r_buff = ft_strdup_g(b->tmp_buff);
	b->tmp_buff = ft_cut(b);
}

char	*get_next_line(int fd)
{
	static t_buff	b;
	char			*r_buff;
	int				r_read;

	if (fd < 0 || 3 < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	r_read = 1;
	r_buff = NULL;
	b.buff = (char *)malloc((3 * sizeof(char)) + 1);
	if (b.buff == NULL)
		return (NULL);
	while (r_read > 0)
	{
		r_read = read(fd, b.buff, 3);
		b.buff[r_read] = '\0';
		if (r_read == 0)
			break ;
		b.tmp_buff = ft_strjoin_g(b.tmp_buff, b.buff);
		if (ft_strlen_nl_g(b.tmp_buff) != -1)
			break ;
	}
	if (b.tmp_buff != NULL)
		ft_re_buff(&r_buff, &b);
	free(b.buff);
	return (r_buff);
}
