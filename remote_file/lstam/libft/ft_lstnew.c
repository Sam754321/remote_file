/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 07:53:08 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/08 05:02:07 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*new;

	new = NULL;
	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		if (content == NULL || content_size == 0)
		{
			new->content = NULL;
			new->content_size = 0;
		}
		else if (content_size != 0)
		{
			new->content = ft_memalloc(content_size);
			ft_memcpy(new->content, content, content_size);
			new->content_size = content_size;
		}
		new->next = NULL;
	}
	return (new);
}
