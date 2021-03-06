#include "minishell.h"

int	ft_putint(int c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *c)
{
	return (write(1, c, ft_strlen(c)));
}

void	make_bs(int *n)
{
	tputs(cursor_left, 1, ft_putint);
	tputs(tgetstr("dc", 0), 1, ft_putint);
	(*n)--;
}

void	init_term(struct termios *old)
{
	struct termios	new;

	tcgetattr(0, old);
	new = *old;
	new.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &new);
	tgetent(0, getenv("TERM"));
	ft_putstr(tgetstr("ks", 0));
}

void	make_lr(char *c, int *n, char *buf, int size)
{
	if (!ft_strcmp(c, tgetstr("kl", 0)))
	{
		if (*n)
		{
			tputs(cursor_left, 1, ft_putint);
			(*n)--;
		}
	}
	else if (!ft_strcmp(c, tgetstr("kr", 0)))
	{
		if (*n < ft_strlen(buf + size * 4000))
		{
			tputs(cursor_right, 1, ft_putint);
			(*n)++;
		}
	}
}
