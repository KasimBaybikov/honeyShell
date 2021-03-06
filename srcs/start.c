#include "minishell.h"

int	g_state;

void	start_term(struct termios *old)
{
	init_term(old);
	tputs(save_cursor, 1, ft_putint);
	ft_putstr("🚀 $ ");
}

void	read_cmnd(t_ar *ar, char *c)
{
	g_state = 0;
	ar->r = read(0, c, 5);
	c[ar->r] = 0;
	if (g_state == 2)
	{
		ar->n = 0;
		g_state = 0;
	}
}

void	last_step(struct termios *old, t_tokens *tkn, t_all *all)
{
	g_state = 1;
	work_command(all, tkn, old);
	free_split(all->all_args);
}

/*
void	mne_poh()
{

}
*/

void	start(t_ar *ar, char *buf, t_all *all)
{
	char			c[5];
	t_tokens		*tkn;
	struct termios	old;

	while (ft_strcmp(c, "\4"))
	{
		start_term(&old);
		while (1)
		{
			read_cmnd(ar, c);
			if (check_key(c))
				make_key(c, ar, &buf);
			else if (!ft_strcmp(c, "\4") && !ar->n)
				break ;
			else
				write_buf(buf, ar, c);
			if (!ft_strcmp(c, "\n"))
			{
				tkn = next_command(buf, ar);
				if (tkn)
					last_step(&old, tkn, all);
				break ;
			}
		}
	}
}
