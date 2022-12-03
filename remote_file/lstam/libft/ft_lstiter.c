/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:52:25 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/08 05:42:08 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *temp;
	t_list *temp1;

	temp = NULL;
	if (lst)
	{
		temp = lst->next;
		(*f)(lst);
	}
	while (temp)
	{
		temp1 = temp->next;
		(*f)(temp);
		temp = temp1;
	}
}
