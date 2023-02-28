/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shdec.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 04:02:03 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/19 04:02:04 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_promptstart(int mode)
{
	char	*str;

	str = NULL;
	if (mode == 23)
		str = PROMPT;
	else if (mode == 5)
		str = CLEAR;
	return (str);
}

void	ft_promptpare(int ac, char **av, t_shell *shell)
{
	if (ac > 3)
		shell->decor->pmptstr = ft_strjoin(av[3], " > ");
	if (ac > 2)
	{
		ft_avjoin(av[2], 2, shell);
		if (ac == 3)
			shell->decor->pmptstr = ft_promptstart(23);
	}
	if (ac > 1)
	{
		ft_avjoin(av[1], 1, shell);
		if (ac < 4)
			shell->decor->pmptstr = ft_promptstart(23);
		if (ac < 3)
			shell->decor->inpclr = ft_promptstart(5);
	}
	if (ac == 1)
	{
		shell->decor->pmptclr = ft_promptstart(5);
		shell->decor->inpclr = ft_promptstart(5);
		shell->decor->pmptstr = ft_promptstart(23);
	}
}

void	ft_avjoin(char *av, int mode, t_shell *shell)
{
	char	*si;

	if (ft_strncmp(av, "red", 3) == 0)
		si = RED;
	else if (ft_strncmp(av, "green", 5) == 0)
		si = GREEN;
	else if (ft_strncmp(av, "blue", 4) == 0)
		si = BLUE;
	else if (ft_strncmp(av, "cyan", 4) == 0)
		si = CYAN;
	else if (ft_strncmp(av, "yellow", 6) == 0)
		si = YELLOW;
	else
		si = NULL;
	if (mode == 1)
	{
		shell->decor->pmptclr = malloc(sizeof(char *) * (ft_strlen(si) + 1));
		shell->decor->pmptclr = si;
	}
	else
	{
		shell->decor->inpclr = malloc(sizeof(char *) * (ft_strlen(si) + 1));
		shell->decor->inpclr = si;
	}
}
