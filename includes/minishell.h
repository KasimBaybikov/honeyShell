/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvernon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:57:18 by rvernon           #+#    #+#             */
/*   Updated: 2021/03/23 19:41:08 by rvernon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <termios.h>
# include "libft.h"

typedef struct	s_all
{
	char 		**env;
}				t_all;

void	init_all(t_all *all);
# endif
