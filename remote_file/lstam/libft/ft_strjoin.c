/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 03:20:06 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/07 06:00:22 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*new;

	i = 0;
	j = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	new = NULL;
	if ((new = (char*)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			if (i < ft_strlen(s1))
				new[i] = s1[i];
			else
			{
				new[i] = s2[j];
				j++;
			}
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
