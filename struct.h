/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmikada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:52:36 by pmikada           #+#    #+#             */
/*   Updated: 2023/02/25 13:52:38 by pmikada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_env
{
	char	**tmp_env;
	char	**export;
}	t_env;

typedef struct s_envargetter
{
	int		j;
	char	*evchar;
	int		k;
}	t_envargetter;

typedef struct s_parinsert
{
	int	i;
	int	j;
	int	k;
	int	l;
}	t_parinsert;

typedef struct s_lex
{
	int			cindex;
	char		*trimstr;
	char		*allstr;
	char		**lexed;
	char		***lextable;
	int			qmode;
}	t_lex;

typedef struct s_par
{
	char			**cmd;
	char			**i_tab;
	char			**o_tab;
	struct s_par	*next;
	struct s_par	*prev;
}	t_par;

typedef struct s_decor
{
	char	*pmptclr;
	char	*inpclr;
	char	*pmptstr;
	char	*pmptfull;
	char	*fullpmt;
}	t_decor;

typedef struct s_intvar
{
	int	q;
	int	st;
	int	ed;
	int	i;
	int	m;
	int	n;
}	t_intvar;

typedef struct s_exp
{
	char			**envar;
	char			**fullvar;
	char			**i_tab;
	char			**full_i;
	char			**o_tab;
	char			**full_o;
	struct s_exp	*next;
	struct s_exp	*prev;
}	t_exp;

typedef struct s_cmd
{
	char			**cmd;
	char			*pth;
	char			**i_tab;
	int				*sign_i;
	char			**o_tab;
	int				*sign_o;
	int				in_count;
	int				out_count;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}	t_cmd;

typedef struct s_shell
{
	t_lex	*lex;
	t_par	*par;
	t_decor	*decor;
	t_exp	*exp;
	t_cmd	*tcmd;
}	t_shell;

#endif
