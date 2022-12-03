/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 06:09:59 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/08 06:19:36 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **lst, t_list *new)
{
	t_list *temp;

	if (!lst)
		return ;
	if (*lst)
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	else if (new)
		*lst = new;
}
