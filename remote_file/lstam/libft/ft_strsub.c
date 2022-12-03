/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 03:12:35 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 05:04:29 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(const char *str, unsigned int start, size_t len)
{
	size_t			i;
	char			*new;

	i = 0;
	if ((new = (char*)malloc(sizeof(char) * (len + 1))))
	{
		while (i < len)
		{
			new[i] = str[start];
			i++;
			start++;
		}
		new[i] = '\0';
	}
	else
		new = NULL;
	return (new);
}
