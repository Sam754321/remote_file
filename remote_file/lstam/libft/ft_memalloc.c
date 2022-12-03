/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:29:15 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/18 08:47:45 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new;

	if (size <= 0)
		return (NULL);
	if ((new = malloc(sizeof(void*) * size)))
		ft_bzero(new, size);
	else
		new = NULL;
	return (new);
}
