/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freellist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 01:59:49 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 01:59:50 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putnull(t_infos *node)
{
	node->extend = NULL;
	node->path = NULL;
	node->name = NULL;
	node->uid = NULL;
	node->group = NULL;
	node->nxt = NULL;
}

void	ft_freellist(t_infos *llist)
{
	t_infos *tmp;
	t_infos *tmp2;

	tmp = llist;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->extend)
			free(tmp->extend);
		if (tmp->uid)
			free(tmp->uid);
		if (tmp->path)
			free(tmp->path);
		if (tmp->group)
			free(tmp->group);
		if (tmp->name)
			free(tmp->name);
		tmp2 = tmp->nxt;
		if (tmp)
			free(tmp);
		tmp = tmp2;
	}
}

int		fillflag1(char argv, int flag)
{
	if (argv == 'l')
		flag = flag | FLAG_L;
	if (argv == 'R')
		flag = flag | FLAG_CAP_R;
	if (argv == 'a')
		flag = flag | FLAG_A;
	if (argv == 't')
		flag = flag | FLAG_T;
	if (argv == 'r')
		flag = flag | FLAG_R;
	if (argv == 'U')
		flag = flag | FLAG_U;
	if (argv == 'c')
		flag = flag | FLAG_C;
	if (argv == 'S')
		flag = flag | FLAG_CAP_S;
	if (argv == 'u')
		flag = flag | FLAG_MIN_U;
	if (argv == 'A')
		flag = flag | FLAG_CAP_A;
	return (flag);
}

int		fillflag2(char argv, int flag)
{
	if (argv == 'f')
		flag = flag | FLAG_F;
	if (argv == 'T')
		flag = flag | FLAG_CAP_T;
	if (argv == 'g')
		flag = flag | FLAG_G;
	if (argv == 'o')
		flag = flag | FLAG_O;
	if (argv == 'F')
		flag = flag | FLAG_CAP_F;
	if (argv == 'p')
		flag = flag | FLAG_P;
	if (argv == 'd')
	{
		flag = flag | FLAG_D;
		flag = flag | FLAG_A;
	}
	if (argv == 'p' && flag & FLAG_CAP_F)
		flag = flag - FLAG_CAP_F;
	if (argv == '1' && flag & FLAG_L)
		flag = flag - FLAG_L;
	if (argv == '1' && flag & FLAG_G)
		flag = flag - FLAG_G;
	return (flag);
}

int		fillflag3(char argv, int flag)
{
	if (argv == '1' && flag & FLAG_O)
		flag = flag - FLAG_O;
	if (argv == '1' && flag & FLAG_COL)
		flag = flag - FLAG_COL;
	if (argv == 'C')
		flag = flag | FLAG_COL;
	if (argv == 'u' && flag & FLAG_U)
		flag = flag - FLAG_U;
	if (argv == 'u' && flag & FLAG_C)
		flag = flag - FLAG_C;
	if (argv == 'U' && flag & FLAG_MIN_U)
		flag = flag - FLAG_MIN_U;
	if (argv == 'U' && flag & FLAG_C)
		flag = flag - FLAG_C;
	if (argv == 'c' && flag & FLAG_MIN_U)
		flag = flag - FLAG_MIN_U;
	if (argv == 'c' && flag & FLAG_U)
		flag = flag - FLAG_U;
	if (argv == 'G')
		flag = flag | FLAG_CAP_G;
	return (flag);
}
