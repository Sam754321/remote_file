/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:59:06 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 01:59:07 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	normaldisplay2(t_infos *tmp, t_opt *option, int fold)
{
	if ((fold == 1) && (tmp->type == 3))
		return (0);
	else
	{
		set_color(tmp->type, option->flag, tmp->rights);
		ft_putstr(tmp->name);
		reset_color(option->flag);
		if (option->flag & FLAG_CAP_F)
			ft_putcapf(tmp->rights, option->flag);
		if (option->flag & FLAG_P && tmp->type == 3)
			ft_putchar('/');
		ft_putchar('\n');
		return (1);
	}
}

void		display_err(t_err *error)
{
	while (error)
	{
		ft_putstr_fd("ls: ", 2);
		ft_putstr_fd(error->err_name, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd("No such file or directory", 2);
		error = error->nxt;
	}
}

int			normaldisplay(t_infos *llist, t_opt *option, int fold)
{
	t_infos		*tmp;
	int			ret;

	tmp = llist;
	ret = 0;
	while (tmp)
	{
		if ((tmp->name[0] != '.' || option->flag & FLAG_A) ||\
			((ft_checkpoints(tmp->name) == 1) && option->flag & FLAG_CAP_A) ||\
			option->flag & FLAG_F)
		{
			if (normaldisplay2(tmp, option, fold) == 0)
				ft_putstr("");
			else
				ret = 1;
		}
		tmp = tmp->nxt;
	}
	return (ret);
}

int			display(t_infos *llist, t_opt *option, int fold)
{
	if (option->flag & FLAG_L || option->flag & FLAG_G || option->flag & FLAG_O)
		return (display_l(llist, option, fold));
	else if (option->flag & FLAG_COL)
		return (display_col(llist, option, fold));
	else
		return (normaldisplay(llist, option, fold));
}

void		displaydirs(t_infos *llist, t_opt *option, int n)
{
	t_infos *tmp;
	t_infos *tmp2;

	tmp = llist;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->type == 3)
		{
			if (n == 1)
				ft_putchar('\n');
			if (n != 2)
			{
				ft_putstr(tmp->path);
				ft_putendl(":");
			}
			tmp2 = ft_listdir(tmp->path, tmp->name, option);
			display(tmp2, option, 0);
			n = 1;
			if (tmp2)
				ft_freellist(tmp2);
		}
		tmp = tmp->nxt;
	}
}
