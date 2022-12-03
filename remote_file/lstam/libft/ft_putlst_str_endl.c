/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 04:39:57 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/08 05:53:19 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlst_str_endl(t_list **lst)
{
	char	*content_str;
	t_list	*temp;
	t_list	*temp2;

	temp = *lst;
	while (temp)
	{
		temp2 = temp->next;
		content_str = (char*)temp->content;
		if (content_str)
		{
			ft_putstr(content_str);
			ft_putchar('\n');
		}
		temp = temp2;
	}
}
