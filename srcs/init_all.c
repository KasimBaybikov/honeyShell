#include "minishell.h"

void	init_all(t_ar *ar, char **buf, t_all *all)
{
	init_ar(ar);
	*buf = malloc(4000 * 1000);
	all->env = 0;
	all->av = 0;
	all->start_line = 0;
	all->command = 0;
	all->args = 0;
	all->all_args = 0;
	all->dots = 0;
	all->files = 0;
	all->exit_status = 0;
}

void	init_cmd(t_cmd *cmd)
{
	cmd->files = 0;
	cmd->cmd = 0;
	cmd->args = 0;
	cmd->pipe = 0;
	cmd->pipe_in = 0;
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	cmd->fds[0] = -1;
	cmd->fds[1] = -1;
}
