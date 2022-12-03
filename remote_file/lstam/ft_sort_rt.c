/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_rt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:01:35 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:01:35 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		rec_add_cap_sr(t_infos *lst, t_infos *new)
{
	if (lst->nxt)
	{
		if (new->size > lst->nxt->size)
			rec_add_cap_sr(lst->nxt, new);
		else if (new->size == lst->nxt->size)
		{
			if (ft_strcmp(new->name, lst->nxt->name) <= 0)
				rec_add_cap_sr(lst->nxt, new);
			else
			{
				new->nxt = lst->nxt;
				lst->nxt = new;
			}
		}
		else
		{
			new->nxt = lst->nxt;
			lst->nxt = new;
		}
	}
	else if (lst->nxt == NULL)
		lst->nxt = new;
	else
		rec_add_cap_sr(lst->nxt, new);
}

static void		rec_add_cap_s(t_infos *lst, t_infos *new)
{
	if (lst->nxt)
	{
		if (new->size < lst->nxt->size)
			rec_add_cap_s(lst->nxt, new);
		else if (new->size == lst->nxt->size)
		{
			if (ft_strcmp(new->name, lst->nxt->name) >= 0)
				rec_add_cap_s(lst->nxt, new);
			else
			{
				new->nxt = lst->nxt;
				lst->nxt = new;
			}
		}
		else
		{
			new->nxt = lst->nxt;
			lst->nxt = new;
		}
	}
	else if (lst->nxt == NULL)
		lst->nxt = new;
	else
		rec_add_cap_s(lst->nxt, new);
}

t_infos			*ft_sort_cap_s(t_infos *lst, t_infos *node)
{
	t_infos *temp;

	temp = lst;
	if (node->size > temp->size)
	{
		node->nxt = temp;
		lst = node;
		return (lst);
	}
	else if (temp->nxt == NULL)
	{
		temp->nxt = node;
		return (lst);
	}
	else
		rec_add_cap_s(temp, node);
	return (lst);
}

t_infos			*ft_sort_cap_sr(t_infos *lst, t_infos *node)
{
	t_infos *temp;

	temp = lst;
	if (node->size < temp->size)
	{
		node->nxt = temp;
		lst = node;
		return (lst);
	}
	else if (temp->nxt == NULL)
	{
		temp->nxt = node;
		return (lst);
	}
	else
		rec_add_cap_sr(temp, node);
	return (lst);
}
