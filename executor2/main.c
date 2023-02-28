#include "../minishell.h"

static void	ft_tmp_env(t_data *data, char **env)
{
	int	len;
	int	i;

	len = ft_strlen_c2d(env);
	data->env = malloc(sizeof(char *) * (len + 1));
	if (data->env == NULL)
		return ;
	i = -1;
	while (env[++i])
		data->env[i] = ft_strdupp(env[i]);
	data->env[i] = NULL;
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;
	t_data	data;
	int		exit_s;
	t_cmd	cmd;
	t_cmd	cmd2;

	char *cmdd[] = {NULL};
	char *i_tabb[] = {"EOF", NULL};
	int	sign_ii[] = {2, 0};
	char *o_tabb[] = {NULL};
	int	*sign_oo[] = {0};
	cmd.cmd = (char **)cmdd;
	cmd.i_tab = (char **)i_tabb;
	cmd.sign_i = (int *)sign_ii;
	cmd.o_tab = (char **)o_tabb;
	cmd.sign_o = (int *)sign_oo;
	cmd.next = &cmd2;

	char *cmdd2[] = {"ls", NULL};
	char *i_tabb2[] = {NULL};
	int	sign_ii2[] = {0};
	char *o_tabb2[] = {NULL};
	int	*sign_oo2[] = {0};
	cmd2.cmd = (char **)cmdd2;
	cmd2.i_tab = (char **)i_tabb2;
	cmd2.sign_i = (int *)sign_ii2;
	cmd2.o_tab = (char **)o_tabb2;
	cmd2.sign_o = (int *)sign_oo2;
	cmd2.next = NULL;

	ft_tmp_env(&data, env);
	exit_s = 0;
	ft_executor(&cmd, &data, &exit_s);
	return (0);
}