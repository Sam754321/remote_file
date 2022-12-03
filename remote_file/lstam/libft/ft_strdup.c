/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 16:36:30 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/06 05:08:55 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*copy;
	int		i;

	i = 0;
	if ((copy = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
	{
		while (str[i] != '\0')
		{
			copy[i] = str[i];
			i++;
		}
		copy[i] = '\0';
	}
	else
		copy = NULL;
	return (copy);
}
