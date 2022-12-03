/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:00:58 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:00:59 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_recurse2(t_opt *option, t_infos *tmp, int n, int i)
{
	if (n == 2)
		;
	else if (option->flag & FLAG_A || tmp->name[0] != '.' ||\
	(i == 1 && tmp->nxt) || (i == 1 && n == 1))
	{
		if (n >= 1)
		{
			ft_putchar('\n');
			n = 1;
		}
		ft_putstr(tmp->path);
		ft_putendl(":");
	}
	return (n);
}

int		ft_isvoid(t_infos *llist)
{
	int		i;

	i = 0;
	while (llist)
	{
		llist = llist->nxt;
		i++;
	}
	if (i > 2)
		return (0);
	else
		return (1);
}

void	ft_ajustmaxsize(t_opt *option)
{
	option->max_nlink = 0;
	option->max_uid = 0;
	option->max_gid = 0;
	option->max_size = 0;
	option->max_maj = 0;
	option->max_min = 0;
	option->total = 0;
}

int		ft_checkpoints(char *name)
{
	int		i;

	i = ft_strlen(name);
	if ((i == 1) && (name[0] == '.'))
		return (0);
	if ((i == 2) && (name[0] == '.' && name[1] == '.'))
		return (0);
	return (1);
}

int		display_recursive(t_infos *infos, t_opt *option, int n, int i)
{
	t_infos *tmp;
	t_infos *tmp2;

	tmp = infos;
	tmp2 = NULL;
	if (!tmp)
		return (i);
	if ((tmp->type == 3 && (ft_checkpoints(tmp->name) == 1))\
		|| ((ft_checkpoints(tmp->name) == 0) && i == 1))
	{
		tmp2 = ft_listdir(tmp->path, tmp->name, option);
		if (tmp2 != NULL)
			n = ft_recurse2(option, tmp, n, i);
		if (option->flag & FLAG_A || tmp->name[0] != '.' || i == 1)
			display(tmp2, option, 0);
		ft_ajustmaxsize(option);
		if (tmp2)
			display_recursive(tmp2, option, n, i - 1), ft_freellist(tmp2);
	}
	n = 1;
	return (i = display_recursive(tmp->nxt, option, n, i));
}
