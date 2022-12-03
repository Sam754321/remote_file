/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsedigi <tsedigi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 17:50:56 by tsedigi           #+#    #+#             */
/*   Updated: 2014/11/07 00:25:12 by tsedigi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*temp;

	i = 0;
	temp = (char *)s;
	while (temp[i])
	{
		if (temp[i] == c)
		{
			return (&temp[i]);
		}
		i++;
	}
	if (temp[i] == c)
		return (&temp[i]);
	return (NULL);
}
