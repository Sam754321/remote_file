/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/02 02:01:47 by tsedigi           #+#    #+#             */
/*   Updated: 2015/02/02 02:01:48 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		rec_add_t(t_infos *lst, t_infos *new)
{
	if (lst->nxt)
	{
		if (new->date < lst->nxt->date)
			rec_add_t(lst->nxt, new);
		else if (new->date == lst->nxt->date)
		{
			if (ft_strcmp(new->name, lst->nxt->name) >= 0)
				rec_add_t(lst->nxt, new);
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
		rec_add_t(lst->nxt, new);
}

t_infos			*ft_sort_t(t_infos *lst, t_infos *node)
{
	t_infos *temp;

	temp = lst;
	if (node->date > temp->date)
	{
		node->nxt = temp;
		lst = node;
		return (lst);
	}
	else if (node->date == temp->date && ft_strcmp(node->name, temp->name) <= 0)
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
		rec_add_t(temp, node);
	return (lst);
}

static void		rec_add_t_r(t_infos *lst, t_infos *new)
{
	if (lst->nxt)
	{
		if (new->date > lst->nxt->date)
			rec_add_t_r(lst->nxt, new);
		else if (new->date == lst->nxt->date)
		{
			if (ft_strcmp(new->name, lst->nxt->name) <= 0)
				rec_add_t_r(lst->nxt, new);
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
		rec_add_t_r(lst->nxt, new);
}

t_infos			*ft_sort_rt(t_infos *lst, t_infos *node)
{
	t_infos *temp;

	temp = lst;
	if (node->date <= temp->date)
	{
		if (node->date < temp->date || (ft_strcmp(node->name, temp->name) > 0))
		{
			node->nxt = temp;
			lst = node;
			return (lst);
		}
		else if (node->date == temp->date)
			rec_add_t_r(temp, node);
	}
	else if (temp->nxt == NULL)
	{
		temp->nxt = node;
		return (lst);
	}
	else
		rec_add_t_r(temp, node);
	return (lst);
}
