/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_n_l.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:13:13 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/04 19:13:15 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_N_L_H
# define G_N_L_H

typedef struct s_buff
{
	char	*buff;
	char	*tmp_buff;
}	t_buff;

int		ft_strlen_g(char *s);
int		ft_strlen_nl_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
char	*ft_strdup_g(char *s);
char	*get_next_line(int fd);

#endif
