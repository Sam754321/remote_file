/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 09:02:51 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/18 08:48:00 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*temp;

	if (!lst)
		return (NULL);
	if ((new = (*f)(lst)))
	{
		temp = lst->next;
		while (temp)
		{
			ft_lstappend(&new, (*f)(temp));
			temp = temp->next;
		}
	}
	return (new);
}
