/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_couunt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 09:13:42 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/08 09:23:33 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lst_count(t_list *lst)
{
	size_t i;
	t_list *temp;

	i = 0;
	temp = lst;
	if (lst)
	{
		i++;
		while (temp->next)
		{
			i++;
			temp = temp->next;
		}
	}
	return (i);
}
