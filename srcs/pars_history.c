#include "minishell.h"

void	check_symb(char **cmnd, char **tk, int *is_set)
{
	char	t[2];

	t[1] = 0;
	t[0] = **cmnd;
	*tk = ft_strjoin(*tk, t);
	if (**cmnd)
		(*cmnd)++;
	*is_set = 1;
}

int	check_all(char **cmnd, char **tk, int *is_set)
{
	if (**cmnd == '\'')
	{
		if (!check_sing_quot(cmnd, is_set, tk))
			return (0);
	}
	else if (**cmnd == '\\')
	{
		if (!check_bs(cmnd, tk, is_set))
			return (0);
	}
	else if (**cmnd == '\"')
	{
		if (!check_dbl_quot(cmnd, tk, is_set))
			return (0);
	}
	else
		check_symb(cmnd, tk, is_set);
	return (1);
}

int	check_else(char **cmnd, t_tokens *tmp, int *is_set)
{
	char	*tk;

	tk = malloc(1);
	tk[0] = '\0';
	while (not_operator(**cmnd) && **cmnd != ' ' && **cmnd != '\0')
	{
		if (!check_all(cmnd, &tk, is_set))
		{
			free(tk);
			return (0);
		}
	}
	tmp->token = tk;
	tmp->next = NULL;
	tmp->is_oprt = 0;
	return (1);
}

t_tokens	*flexer(char *cmnd)
{
	t_tokens	*tkn;
	t_tokens	*tmp;
	int			is_set;

	tkn = NULL;
	while (*cmnd)
	{
		is_set = 0;
		tmp = malloc(sizeof(t_tokens));
		while (*cmnd == ' ' && *cmnd)
			cmnd++;
		if (*cmnd == '\0')
			break ;
		if (!not_operator(*cmnd))
			check_operator(tmp, &cmnd, &is_set);
		else
		{
			if (!check_else(&cmnd, tmp, &is_set))
				return (0);
		}
		if (is_set)
			add_elem(&tkn, tmp);
	}
	return (tkn);
}
