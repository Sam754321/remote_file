/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:58:38 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 01:58:40 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	full_display_l(t_infos *tmp, t_opt *option, char tab[1024])
{
	if ((tmp->name[0] != '.' || option->flag & FLAG_A) ||\
		(ft_checkpoints(tmp->name) == 1 && option->flag & FLAG_CAP_A)\
		|| option->flag & FLAG_F)
	{
		first_display_l(tmp, option);
		second_display_l(tmp, option);
		time(&option->rtime);
		option->realtime = ctime(&tmp->date);
		t3_display_l(tmp, option, option->rtime, option->realtime);
		fourth_display_l(tmp, option, tab);
	}
}

t_infos *ft_pushback(t_infos *llist, t_infos *node)
{
	t_infos *tmp;

	tmp = llist;
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	tmp->nxt = node;
	return (llist);
}

void	ft_putcapf(char *s, int flag)
{
	if (s[0] == 'd' && flag & FLAG_P)
		;
	else if (s[0] == 'd')
		ft_putchar('/');
	if (s[0] == 'l')
		ft_putchar('@');
	if (s[0] == 's')
		ft_putchar('=');
	if (s[0] == 'p')
		ft_putchar('|');
	if (ft_strchr(s, 'x') != NULL && s[0] == '-')
		ft_putchar('*');
}

void	ft_putspace(int nb, int max)
{
	while (nb < max)
	{
		ft_putchar(' ');
		nb++;
	}
}

void	ft_put_total(int fold, t_opt *option, t_infos *llist)
{
	if ((fold == 0 && (ft_isvoid(llist) == 0)) || (option->flag & FLAG_A))
	{
		if (option->flag & FLAG_D)
			;
		else
		{
			ft_putstr("total ");
			ft_putnbr(option->total);
			ft_putchar('\n');
		}
	}
}
