/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 02:38:13 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 03:33:06 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = (char *)malloc(sizeof(char) * (size + 1))))
	{
		while (i <= size)
		{
			new[i] = '\0';
			i++;
		}
	}
	else
		new = NULL;
	return (new);
}
