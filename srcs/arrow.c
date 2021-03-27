/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchaya <mchaya@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:33:09 by mchaya            #+#    #+#             */
/*   Updated: 2021/03/27 16:58:57 by mchaya           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <term.h>
#include <curses.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include "libft.h"

int ft_putint(int c)
{
	return (write(1, &c, 1));
}

void	exit_terminal(void)
{
	printf("%s", tgetstr("ke", 0));
	printf("%s", tgetstr("ei", 0));
}

int main() 
{
	struct termios new;
	struct termios old;
	char c[5];
	char *buf;
	int i;
	int n;

	i = 0;
	n = 0;
	tcgetattr(0, &old);
	new = old;
	new.c_lflag &= ~(ECHO);
	new.c_lflag &= ~(ICANON);
	tcsetattr(0, TCSANOW, &new);
	tgetent(0, getenv("TERM"));
	setvbuf(stdout,NULL,_IONBF,0);
	printf("%s", tgetstr("ks", 0));
//	tputs(restore_cursor, 1, ft_putint);
//	tputs(tigetstr("ed"), 1, ft_putint);
	printf("%s", tgetstr("im", 0));
	buf = malloc(4000 * 1000);
	while (ft_strcmp(c, "\4"))
	{
		tputs(save_cursor, 1, ft_putint);
		while (1)
		{

//			ioctl(0, FIONREAD, &n);
			int r = read(0, c, 10);
			c[r] = 0;
			int l;
			l = n;
			if (!ft_strcmp(c, tgetstr("ku", 0)))
			{
				tputs(restore_cursor, 1, ft_putint);
				tputs(tgetstr("dl", 0), 1, ft_putint);
				if (i)
				{
					i--;
					write(1, buf + i * 4000, ft_strlen(buf + i * 4000));
					n = ft_strlen(buf + i * 4000);
				}
			}
			else if (!ft_strcmp(c, tgetstr("kd", 0)))
			{
				tputs(restore_cursor, 1, ft_putint);
				tputs(tgetstr("dl", 0), 1, ft_putint);
				i++;
				write(1, buf + i * 4000, ft_strlen(buf + i * 4000));
				n = 4;
			}
			else if (!ft_strcmp(c, "\177"))
			{
				if (n)
				{
					tputs(cursor_left, 1, ft_putint);
					tputs(tgetstr("dc", 0), 1, ft_putint);
					n--;
				}
			}
			else if (!ft_strcmp(c, tgetstr("kl", 0)))
			{
				while (n)
				{
					tputs(cursor_left, 1, ft_putint);
					n--;
				}
			}
			else if (!ft_strcmp(c, tgetstr("kr", 0)))
			{
				int k = n;
				 (k != n)
				{
					tputs(cursor_right, 1, ft_putint);
					k++;
				}
			}
			else
			{
				write(1, c, r);
				if (ft_strcmp(c, "\n"))
					buf[i * 4000 + n++] = *c;
			}
			if (!ft_strcmp(c, "\n") || !ft_strcmp(c, "\4"))
			{
				buf[i * 4000 + n] = 0;
				if (ft_strcmp(buf + (i * 4000), "\n"))
					i++;
				n = 0;
				buf[i * 4000] = 0;
				break;
			}
		}
	}
//	printf("%s", tgetstr("ke", 0));
	tcsetattr(0, TCSANOW, &old);
	printf("\n");
	return 0;
}