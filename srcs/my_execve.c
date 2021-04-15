/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:24:12 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/15 17:04:32 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *get_env(t_all *all, char *line)
{
	(void)line;
	int index;
	int i;
	char *ret;

	i = -1;
	index = find_name(all, line) - 1;
	if (index != -1)
	{
		ret = all->env[index];
		while (all->env[index] && all->env[index][++i] != '=')
			ret++;
		return ++ret;
	}
	return (0);
}

char *search_path(char **path)
{
	int i;
	struct stat buf;
	char *ret;

	i = -1;
	while (path[++i])
	{
		if (stat(path[i], &buf) == 0)
			ret = ft_strdup(path[i]);
	}
	return (ret);
}

char *find_in_path(t_all *all, char *command)
{
	char **path;
	int i;
	char *ret;

	i = -1;
	path = ft_split(get_env(all, "PATH"), ':');
	if (!path)
		return (0);
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], command);
	}
	ret = search_path(path);	
	free_split(path);
	return (ret);
}

void	my_execve(t_all *all, char **args)
{
	char	*bin;
	pid_t	pid;

	bin = find_in_path(all, args[0]);
	if (!bin)
	{
		ft_putstr_fd("🚀: cd: ", 2);
		ft_putstr_fd(args[0], 2);
		ft_putendl_fd(" : command not found", 2);
		return ;
	}
	pid = fork();
	waitpid(pid, 0, 0);
	if (pid == 0)
	{
		execve(bin, all->args, all->env);
		exit(0);
	}
	free(bin);
}
