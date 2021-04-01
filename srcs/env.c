/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 12:35:10 by rvernon           #+#    #+#             */
/*   Updated: 2021/04/01 18:57:24 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		env(char **s)
{
	int i;

	i = -1;
	while (s[++i])
	{
		printf("%s\n", s[i]);
	}
	return (0);
}
