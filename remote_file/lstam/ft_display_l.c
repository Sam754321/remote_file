/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_l.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:59:19 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 01:59:20 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	first_display_l(t_infos *tmp, t_opt *option)
{
	ft_putstr(tmp->rights);
	ft_putchar(' ');
	ft_putspace(ft_sizeint(tmp->nlinks), option->max_nlink);
	ft_putnbr(tmp->nlinks);
	ft_putchar(' ');
	if (option->flag & FLAG_G)
		;
	else
		ft_putstr(tmp->uid);
	if (option->flag & FLAG_G)
		;
	else
		ft_putspace(ft_strlen(tmp->uid), option->max_uid + 2);
	if (option->flag & FLAG_O)
		;
	else
		ft_putstr(tmp->group);
	if (option->flag & FLAG_O)
		;
	else
		ft_putspace(ft_strlen(tmp->group), option->max_gid + 2);
	if (option->flag & FLAG_O && option->flag & FLAG_G)
		ft_putstr("  ");
}

void	second_display_l(t_infos *tmp, t_opt *option)
{
	int			ismaj;

	ismaj = option->fmaj;
	if ((ismaj) && (tmp->type != 3) && (tmp->type != 5))
	{
		ft_putspace(ft_sizeint(tmp->maj), option->max_maj);
		ft_putnbr(tmp->maj);
		ft_putchar(',');
		ft_putspace(ft_sizeint(tmp->min), option->max_min + 1);
		ft_putnbr(tmp->min);
	}
	else if (ismaj)
	{
		ft_putspace(0, (option->max_maj + option->max_min + 1));
		ft_putnbr(tmp->size);
	}
	else
	{
		ft_putspace(ft_sizeint(tmp->size), option->max_size);
		ft_putnbr(tmp->size);
	}
	ft_putchar(' ');
}

void	t3_display_l(t_infos *tmp, t_opt *option, time_t rtime, char *rea)
{
	char *tmp2;

	if (option->flag & FLAG_CAP_T)
		tmp2 = ft_strsub(rea, 4, 20), ft_putstr(tmp2), free(tmp2);
	else
	{
		if (((rtime - VAL > tmp->date) || (tmp->date > rtime)) && ch(rea))
		{
			option->yolo = 3;
			while (option->yolo++ < 10 && (rea))
				ft_putchar(rea[option->yolo]);
			ft_putchar(' '), option->yolo = 19;
			while (option->yolo++ < 23 && (rea))
				ft_putchar(rea[option->yolo]);
		}
		else if (((rtime - VAL > tmp->date) || (tmp->date > rtime)) && !ch(rea))
			t4_display_l(rea, option);
		else
		{
			option->tmpsub = ft_strsub(rea, 4, 12);
			ft_putstr(option->tmpsub), free(option->tmpsub);
		}
	}
}

void	fourth_display_l(t_infos *tmp, t_opt *option, char tab[1024])
{
	ft_putchar(' ');
	set_color(tmp->type, option->flag, tmp->rights);
	ft_putstr(tmp->name);
	reset_color(option->flag);
	if (option->flag & FLAG_CAP_F)
		ft_putcapf(tmp->rights, option->flag);
	if (option->flag & FLAG_P && tmp->type == 3)
		ft_putchar('/');
	if (tmp->type == 5)
	{
		ft_bzero(tab, 1024);
		readlink(tmp->path, tab, 1024);
		ft_putstr(" -> ");
		ft_putstr(tab);
	}
	ft_putchar('\n');
}

int		display_l(t_infos *llist, t_opt *option, int fold)
{
	t_infos		*tmp;
	char		tab[1024];

	ft_bzero(tab, 1024);
	tmp = llist;
	if (!tmp || (fold == 1 && tmp->type == 3))
		return (0);
	ft_put_total(fold, option, llist);
	while (tmp)
	{
		full_display_l(tmp, option, tab);
		tmp = tmp->nxt;
	}
	return (1);
}
