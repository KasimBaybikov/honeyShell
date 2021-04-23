#include "minishell.h"

int	tkn_size(t_tokens *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

char	**convert_tkn(t_tokens *tkn)
{
	int		n;
	char	**conv;
	int		i;

	i = 0;
	n = tkn_size(tkn);
	conv = malloc(sizeof(char *) * (n + 1));
	conv[n] = 0;
	while (tkn)
	{
		conv[i++] = make_cpy(tkn->token);
		tkn = tkn->next;
	}
	return (conv);
}
